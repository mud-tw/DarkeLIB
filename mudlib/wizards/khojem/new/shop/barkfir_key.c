//  Wizard:  Khojem
//  Barkfir's Key
//  barkfir_key.c
 
#include <std.h>

inherit OBJECT;
 
void create() {
  ::create();
    set_name("barkfir's key");
    set_id( ({ "barkfir's key", "key" }) );
    set_short("barkfir's key");
    set_long("A small, simple wood key unadored with markings.\n");
    set_weight(1);
    set_value(0);
}

