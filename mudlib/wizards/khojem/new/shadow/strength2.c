//  Wizard: Khojem
//  +2 strength stat shadow
//  strength2.c
//	DarkeLIB 0.1
//	Diewarzau 3/27/94

#include <security.h>
inherit "/std/spells/shadows/shadow";

string stat, mesg;
int mod;
object who_shadowed;

void create() {
	seteuid(getuid());
	stat = "strength";
	mod = 2;
}

void set_stat(string arg) { stat = arg; }

void set_mod(int arg) { mod = arg; }

int start_shadow(object ob) {
    seteuid(UID_SHADOW);
    begin_shadow(ob);
    seteuid(getuid());
    who_shadowed = ob;
    return 1;
}

int query_stats(string str) {
    if(!stat || stat != lower_case(str)) return
	(int)shadowp(this_object())->query_stats(str);
    return (int)next_shadow("query_stats")->query_stats(str) + mod;
}

void remove() {
    if(!::remove()) return;
    return;
}

