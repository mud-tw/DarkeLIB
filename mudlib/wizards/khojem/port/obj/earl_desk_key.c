//  Wizard:  Khojem
//  Earl's Key
//  earl_desk_key.c
 
#include <std.h>

inherit OBJECT;
 
void create() {
  ::create();
    set_name("earl's key");
    set_id( ({ "earl's key", "key", "earl_desk_key" }) );
    set_short("earl's key");
    set_long("A heavy, brass key");
    set_weight(10);
    set_value(0);
}

