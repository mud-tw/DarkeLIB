//  Wizard:  Khojem
//  Pirate Key
//  pirate_key.c
 
#include <std.h>

inherit OBJECT;
 
void create() {
  ::create();
    set_name("an iron key");
    set_id( ({ "pirate_captain_key", "key", "iron key" }) );
    set_short("iron key");
    set_long("A heavy, iron key.\n");
    set_weight(10);
    set_value(0);
}

