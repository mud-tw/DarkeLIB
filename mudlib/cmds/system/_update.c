//      /bin/system/_update.c
//      from the Nightmare Mudlib
//      destructs an old version of a file and loads a new one
//      created by Sulam 911219
//      security changes by Descartes of Borg 930810
//      Modified 4/9/96 by Diewarzau to support wildcards.

#include <std.h>
#include <rooms.h>
#include <security.h>
#include <move.h>

inherit DAEMON;

dd(args...)
{
    int i = 0, m = sizeof(args);
    while (i<m-1) {
        write(sprintf("%O", args[i]));
        i++;
    }
}

int cmd_update(string str)
{
    object *ob;
    object obb, ob2;
    string file, res, *list, *dirs, path;
    int n, i, master_flag;

    if (ambassadorp(previous_object()))
        return 0;

    this_player()->set("error report", 0);

    if(!str || str == "here") {
        if(!environment(this_player())) {
            write("No environment!");
            return 1;
        }
        obb = environment(this_player());
        file = file_name(obb);
        message("Nsystem", "Update environment ("+file+"): ", this_player());
        ob = all_inventory(obb);
        for (n = 0; n < sizeof(ob); n++) {
            if (ob[n]->is_player()) ob[n]->move(ROOM_VOID);
        }
        seteuid(getuid(previous_object()));
        destruct(obb);
        seteuid(UID_ROOT);
        if(this_player()->move(file) != MOVE_OK) {
            for (n = 0; n < sizeof(ob); n++) {
                if (ob[n]->is_player()) {
                    ob[n]->move(ROOM_VOID);
                    message("system","Moving to void",ob[n]);
                }
            }
            message("system", "Error in loading file.", this_player());
        } else {
            for (n = 0; n < sizeof(ob); n++) {
                if( ob[n] ) /* something may have happened during the update */
                    ob[n]->move(environment(this_player()));
            }
            message("system", "Ok.", this_player());
        }

        if(this_player()->query("error report")) {
            printf("Runtime errors occurred in the execution.\n"
                "Would you like to view the error report (y/n)? ");
            input_to((: call_other, "/cmds/system/handler", "handle_error" :), 0, this_player(),
                (string)this_player()->query("error report"));
        }
        return 1;
    }

    seteuid(getuid(previous_object()));
    str = resolv_path((string)this_player()->get_path(), str);
    //* Have to do special things for the master object * /
    if(file_size(str + ".c") >= 1) str += ".c";
    if(file_size(str) == -2) {
        write("You cannot update a directory.");
        return 1;
    }
    list = get_dir(str);
    if(!list || !sizeof(list)) {
        write("No such file or directory.");
        return 1;
    }
    dirs = explode(str, "/");
    while((i=member_array("", dirs)) >= 0)
        dirs = exclude_array(dirs, i);

    i = sizeof(dirs) - 2;
    if(i == 0) path = "/"+dirs[0];
    else if(i > 0) path = "/"+implode(dirs[0..i], "/");
    else path = "/";

    i = sizeof(list);
    while(i--) {
        seteuid(getuid(previous_object()));
        file = path+"/"+list[i];
        if(file_size(file) == -2) {
            write(file+": Directory.");
            continue;
        }
        if(file_size(file) == -1) {
            write(file + ": File not found.");
            continue;
        }
        if((ob2 = find_object(file)) == master()) {
            write("Updating master object...");
            seteuid(UID_FORCE);
            this_player()->force_me("massup /adm/obj/master");
            continue;
        }

        if(ob2) {
            res = catch(ob2->remove());
            if(res) message("system", file+": error in remove()", this_player());

            if(ob2) {
                seteuid(getuid(previous_object()));
                destruct(ob2);
                if(!master_flag) seteuid(UID_SYSTEM);
            }
        }
        if(!find_object(file)) {
            message("system", file+": "+((res=catch(call_other(file,"???"))) ?
                res : "updated and loaded."), this_player());

            if(master_flag) seteuid(UID_SYSTEM);
        } else {
            write(file+": couldn't destruct\n");
            continue;
        }
    }
    seteuid(getuid());

    if(this_player()->query("error report")) {
      printf("Runtime errors occurred in the execution.\n"
        "Would you like to view the error report (y/n)? ");
      input_to((: call_other, "/cmds/system/handler", "handle_error" :), 0, this_player(),
        (string)this_player()->query("error report"));
    }

    return 1;
}

void help() {
    message("help",
      "Syntax: <update [file]>\n\n"
      "Destructs the master object of the file named and then attempts "
      "to reload a new version of it.\n\n"
      "See also: call, clone, cref, dest, dref, load, renew", this_player()
    );
}
