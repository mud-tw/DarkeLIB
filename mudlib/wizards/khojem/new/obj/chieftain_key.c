//  Wizard:  Khojem
//  Chieftain's Key
//  chieftain_key.c
 
#include <std.h>

inherit OBJECT;
 
void create() {
  ::create();
    set_name("chieftain's key");
    set_id( ({ "chieftain's key", "key" }) );
    set_short("chieftain's key");
    set_long("A small, simple metal key unadored with markings.\n");
    set_weight(1);
    set_value(0);
}

