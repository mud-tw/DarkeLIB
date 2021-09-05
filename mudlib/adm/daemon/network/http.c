// rcsid = "$Header: /weaver2/archive/mudlib/single/net/http.c,v 1.12 1995/05/20 12:20:36 garnett Exp $"

// 1995/04/28
//
// An HTTP (World Wide Web) server written in LPC for the Interstice mudlib
// and MudOS v21 driver (using socket efuns).
//
// - this code is copyright 1995 by John Garnett (Truilkan)
//   and Dwayne Fontenot (Jacques).

// - A few bits of code (two or three lines) from the old TMI-2 http.c
//   by George Reese (Descartes) may still be present in this code.
//
// Permission is granted to use this code for any legal purpose but only if 
// these credits are kept with the code.  No warranty is expressed or implied.

// This HTTP server implements some part of HTTP/1.0.  Its not really
// complete but its more complete than the old TMI-2 HTTP server.

// Improvements over the old TMI-2 http.c:
//
// 1) outputs logging information in the NCSA httpd format so all of
//    standard httpd log processing tools should work.
// 2) pays attention to the return code of the socket_write() efun
//    and attempts to do the right thing.
// 3) is able to process large WWW client queries such as those generated by
//    MacWeb (which cause the read_callback to be called multiple times
//    for one query).
// 4) handles hostname resolution more efficiently
// 5) handles the POST method (in addition to GET).

// Change no_one to your name to get debug information to your
// character.
#define DEBUGGER "no_one"

#include <mudlib.h>
#include <config.h>
#include <net/config.h>
#include <net/daemons.h>
#include <daemons.h>
#include <driver/localtime.h>  // this is from the driver include dir
#include <net/http.h>
#include <net/socket.h> // from the driver include dir

// OB_SAVE provides this object with persistency (for saving 'accesses').
// For this to be effective, a shutdown daemon needs to call remove()
// on this object as the MUD is shutting down (this will cause save_object()
// to be called).

inherit SAVE_D;

// Number of times to retry in the event that socket_write() returns
// EESEND or EEWOULDBLOCK.

#define MAXIMUM_RETRIES    3

#define HTTP_HEADER "HTTP/1.0 %s%c"
#define DEFAULT_HEADER "Server: "+mud_name()+"/0.2\nMIME-version: 1.0%c"

#define log_info(x, y) log_file(x, ctime(time()) + "\n"); log_file(x, y)

nosave private int httpSock;
nosave private mapping sockets;
nosave private mapping resolve_pending;
nosave string *months;

nosave private mapping bad_cmd = BAD_CMD;
nosave private mapping access_denied = ACCESS_DENIED;
nosave private mapping not_found = NOT_FOUND;
nosave private mapping bad_gateway = BAD_GATEWAY;

protected void setup();
void close_connection(int fd);
void write_data(int fd, mixed data);

int accesses;

int query_accesses()
{
	return accesses;
}

protected void create()
{ 
	accesses = 0;
	set_persistent(1);
	save::create();
	months = ({"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct",
		"Nov","Dec"});
	sockets = ([]);
	resolve_pending = ([]);
	log_info(LOG_HTTP_ERR, "Created when uptime = " + uptime() + "\n");
	call_out("setup", 5);
}

void
remove()
{
	save::remove();
	log_info(LOG_HTTP_ERR, "Destructed when uptime = " + uptime() + "\n");
	destruct(this_object());
}

string http_header(string code)
{
	return sprintf(HTTP_HEADER, code, 10) + sprintf(DEFAULT_HEADER, 10);
}

string http_error_header(string code)
{
	return http_header(code) + sprintf("Content-type: text/html%c%c", 10, 10);
}

// Leto obsolete here, can get ripped out later
int query_prevent_shadow(object ob)
{
	return 1;
}

varargs string query_hostname(int fd, int t)
{
	mapping entry;
	string name;

	entry = sockets[fd];
	if (!undefinedp(entry)) {
		if (t) {
			return entry["address"];
		} else {
			return entry["name"];
		}
	}
	return 0;
}

protected void clean_up()
{
} 

protected void setup()
{
	if ((httpSock =
		socket_create(STREAM, "read_callback", "close_callback")) < 0)
	{
		log_info(LOG_HTTP_ERR, "setup: Failed to create socket.\n");
		return;
	}
	if (socket_bind(httpSock, PORT_HTTP) < 0) {
		socket_close(httpSock);
		log_info(LOG_HTTP_ERR, "setup: Failed to bind socket to port.\n");
		return;
	}
	if (socket_listen(httpSock, "listen_callback") < 0) {
		socket_close(httpSock);
		log_info(LOG_HTTP_ERR, "setup: Failed to listen to socket.\n");
	}
}

protected void write_data_retry(int fd, mixed data, int counter)
{
	int rc;

	if (counter == MAXIMUM_RETRIES) {
		close_connection(fd);
		return;
	}
	rc = socket_write(fd, data);
HTTP_DEBUG("write_data: rc = " + rc + ", counter = " + counter + "\n");
	sockets[fd]["write_status"] = rc;
	switch (rc) {
		case EESUCCESS:
			// we're finished with this fd.
			close_connection(fd);
			break;
		case EEALREADY:
			// driver must have set the socket marked as BLOCKED when
			// it was created by socket_accept().  Just wait for
			// write_callback to be called so that we can write out the
			// pending data.
			sockets[fd]["pending"] = data;
			break;
		case EECALLBACK:
			// wait for write_callback before accessing socket fd again.
			break;
		case EEWOULDBLOCK:
		case EESEND:
			// try again in two seconds
			if (counter < MAXIMUM_RETRIES) {
				call_out("retry_write", 2, ({fd, data, counter + 1}));
				return;
			}
			// fall through to the default case and write an error.
		default:
			log_info(LOG_HTTP_ERR, "write_data_retry: " + socket_error(rc) + "\n");
			close_connection(fd);
			break;
	}
}

void retry_write(mixed* args)
{
	write_data_retry(args[0], args[1], args[2]);
}

protected void write_data(int fd, mixed data)
{
	write_data_retry(fd, data, 0);
}

protected void store_client_info(int fd)
{
	string addr;
	mixed result;
	int port;

	sscanf(socket_address(fd), "%s %d", addr, port);
	sockets[fd] = ([
	 "address" : addr,
	 "name" : addr,
	 "port" : port,
	 "time" : time(),
	 "write_status" : EESUCCESS
	]);
	result = OB_RESOLVER->query_cache(addr, "resolve_callback");
	if (intp(result)) {
		resolve_pending[result] = fd;
	} else {
		sockets[fd]["name"] = result;
	}
}

protected void listen_callback(int fd)
{
	int nfd;

	if ((nfd = socket_accept(fd, "read_callback", "write_callback")) < 0) {
		log_info(LOG_HTTP_ERR, "listen_callback: socket_accept failed.\n");
		return;
	}
	store_client_info(nfd);
}

//
// The driver calls write_callback to indicate that the data sent
// by the last call to socket_write() is finally all written to the
// network (or to indicate that a socket created in the blocked state
// is now ready for writing).
//

void write_callback(int fd)
{
	// The status will be EEALREADY only in the event that the socket
	// was created in a blocked state (this object is smart enough not
	// to write to a socket it knows is blocked).
	//
	if (sockets[fd]["write_status"] == EEALREADY) {
		write_data(fd, sockets[fd]["pending"]);
		//
		// its safe to delete the pending data now since its already been sent
		// and since we won't ever have any more pending data for this
		// socket (we might have an EECALLBACK but the driver is
		// responsible for holding the pending data in that case).
		//
		map_delete(sockets[fd], "pending");
	} else {
		//
		// We can close the socket at this point since we only ever send one
		// thing on a given socket before we are through with it.
		//
		sockets[fd]["write_status"] = EESUCCESS;
		close_connection(fd);
	}
}

// todo make this a simul_efun

string
common_date(int t)
{
	mixed* r;

	r = localtime(t);
	return sprintf("%02d/%s/%d:%02d:%02d:%02d -%02d00",
		r[LT_MDAY], months[r[LT_MON]], r[LT_YEAR], r[LT_HOUR],
		r[LT_MIN], r[LT_SEC], r[LT_GMTOFF] / 3600);
}

void
log_http(int fd, int rc, int nbytes, string cmd)
{
	string msg;
	string bsent;

	if (!sockets[fd]) {
		return;
	}
	bsent = (nbytes) ? sprintf("%d", nbytes) : "-";
	msg = sprintf("%s unknown - [%s] \"%s\" %d %s\n",
		sockets[fd]["name"], common_date(time()), cmd, rc, bsent);
	log_file(LOG_HTTP, msg);
}

// read_callback gets called when the WWW client sends us a request.
//

void do_get(int, string, string);
void do_post(int, string, string, string);

protected void read_callback(int fd, string str)
{
	string cmd, args, file, url;
	string *request;
	string tmp, line0;

	if (!sizeof(str)) {
		http_error(fd, bad_cmd, "400 Bad Request");
		return;
	}

	if (tmp = sockets[fd]["read"]) {
		str = tmp + str;
	}
	if (str[<1] != '\n') {
		sockets[fd]["read"] = str;
		return;
	} else {
		map_delete(sockets[fd], "read");
	}
	accesses++;
HTTP_DEBUG("read_callback: (" + str + ")\n");
	request = explode(replace_string(str, "\r", ""), "\n");
	line0 = request[0];
	sscanf(line0, "%s %s %s", cmd, file, args);
	switch(lower_case(cmd)) {
		case "get":
			do_get(fd, file, line0);
			break;
		case "post":
			url = request[<1]; // last line of the request
			do_post(fd, file, url, line0);
			break;
		default:
			http_error(fd, bad_cmd, "400 Bad Request");
			break;
	}
}

// close_callback is called when any socket is closed unexpectedly
// (by the driver instead of as a result of socket_close()).

protected void close_callback(int fd)
{
	if (fd == httpSock) {
		log_info(LOG_HTTP_ERR,
			"HTTP socket closed unexpectedly; restarting.\n");
		call_out("setup", 5);
	} else {
		if (undefinedp(sockets[fd])) {
			log_info(LOG_HTTP_ERR,
				sprintf("Client socket %d closed unexpectedly\n", fd));
		} else {
			log_info(LOG_HTTP_ERR,
				sprintf("Client socket %s %d closed unexpectedly.\n",
					sockets[fd]["name"], sockets[fd]["port"]));
		}
		map_delete(sockets, fd);
	}
}

// resolve_callback is called by the resolver object in response to our
// queries to resolve dotted decimal internet addresses into domain name
// style addresses.

void resolve_callback(string theName, string theAddr, int slot)
{
	int *fds;
	int i;
	int fd;

	fd = resolve_pending[slot];
	map_delete(resolve_pending, slot);
	if (!undefinedp(sockets[fd]) && (sockets[fd]["address"] == theAddr)) {
		sockets[fd]["name"] = theName;
	} else {
		log_info(LOG_HTTP_ERR,
			sprintf("Resolved %s to %s after connection closed.\n",
				theAddr, (sizeof(theName) ? theName : "NOT RESOLVED")));
	}
}

private void http_error(int fd, mapping err, string code)
{
	string tens;

	tens = sprintf("%c%c", 10, 10);
	HTTP_DEBUG(http_error_header(code) + read_file(err["file"]) + tens);
	write_data(fd, http_error_header(code) + read_file(err["file"]) + tens);
}

protected void close_connection(int fd)
{
	if (sockets[fd]["write_status"] == EECALLBACK) {
		// write_callback() will call close_connection() when socket fd
		// is drained.
		return;
	}
	map_delete(sockets, fd);
	map_delete(resolve_pending, fd);
	socket_close(fd);
}

// respond to a client request for a file.
//
    
private void do_get(int fd, string file, string line0)
{
	string dir;
	string *parts;
	mixed result;
	string ofile;
	string args, id;

	if (file[0] != '/') file = "/" + file;
	ofile = file;
	parts = explode(file, "/");
	if (!sizeof(parts)) {
		file = sprintf("%s/index.html", DIR_WWW);
	} else if (file[1] == '~') {
		parts[0] = sprintf("%s%s", user_path(parts[0][1..<1]), USER_WWW_SUBDIR);
		file = implode(parts, "/");
	} else if (parts[0] == "user" || parts[0] == "home") {
	    parts[0] = 0;
	    if (parts[1])
		parts[1] = sprintf("%s%s", user_path(parts[1]), USER_WWW_SUBDIR);
	    file = implode(parts, "/");
	} else if (file[0..strlen(DIR_WWW)-1] != DIR_WWW) {
		file = sprintf("%s%s", DIR_WWW, file);
	}
	if (file_size(file) == -2) {
		dir = file;
		file = sprintf("%s/index.html", file);
		if (file_size(file) == -1) {
			file = "/www/gateways/dirlist" + dir;
		}
	}

	HTTP_DEBUG("HTTP:" + file + ", " + sockets[fd]["name"] + "\n");
/* commented out for now, Leto
	if (OB_PERMS->permission(ofile, "www", sockets[fd]["address"]) == 0) {
		log_http(fd, 403, 0, line0);
		http_error(fd, access_denied, "403 Forbidden");
		return;
	}
 */

	if (!strsrch(file, DIR_WWW_GATEWAYS)) {
#if 1
	    if ((sscanf(file, DIR_WWW_GATEWAYS+"/%s?%s", id, args) == 2) ||
	          (sscanf(file, DIR_WWW_GATEWAYS+"/%s/%s", id, args) == 2))
	        file = sprintf(DIR_WWW_GATEWAYS "/%s", id);
	    if (catch(result = file->gateway(args))) {
		log_http(fd, 400, 0, line0);
		http_error(fd, bad_gateway, "400 Bad Request");
		return;
	    }
#else
// Leto commented out the OB_CGI->cgi() call; Robocoder #if'd it out instead
		result = OB_CGI->cgi(fd, file);
		if (result == 400) {
			log_http(fd, 400, 0, line0);
			http_error(fd, bad_gateway, "400 Bad Request");
			return;
		} else if (result == 403) {
			log_http(fd, 403, 0, line0);
			http_error(fd, access_denied, "403 Forbidden");
			return;
		}
#endif
	} else if (!file_exists(file)) {
                // automagically map .html to .c files
                if (!strsrch(file, DIR_WWW) && file[<5..<1] == ".html") {
                    file = file[0..<6];
                    if (file_exists(file + ".c") && catch(result = file->gateway())) {
                        log_http(fd, 400, 0, line0);
                        http_error(fd, bad_gateway, "400 Bad Request");
                        return;
                    }
                } else {
                    log_http(fd, 404, 0, line0);
                    http_error(fd, not_found, "404 Not Found");
                    return;
                }
	} else {
		result = read_buffer(file);
	}
	log_http(fd, 200, sizeof(result), line0);
	write_data(fd, result);
}

private void do_post(int fd, string file, string url, string line0)
{
	do_get(fd, file + "?" + url, line0);
}
