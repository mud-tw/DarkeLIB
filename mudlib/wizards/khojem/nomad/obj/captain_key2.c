//  Wizard:  Khojem
//  captains key 2
//  captains_key2.c
 
#include <std.h>

inherit OBJECT;
 
void create() {
  ::create();
    set_name("captains_key2");
    set_id( ({ "captain's key", "key" }) );
    set_short("a captains_key2");
    set_long("A small metal key.  It is worn and scratched.\n");
    set_weight(1);
    set_value(0);
}

