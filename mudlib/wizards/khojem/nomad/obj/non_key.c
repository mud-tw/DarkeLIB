//  Wizard:  Khojem
//  non Key
//  non_key.c
 
#include <std.h>

inherit OBJECT;
 
void create() {
  ::create();
    set_name("key_that_does_not_exist");
    set_id( ({ "non key", "key" }) );
    set_short("non key");
    set_long("A small key that does not exist.\n");
    set_weight(1);
    set_value(0);
}
