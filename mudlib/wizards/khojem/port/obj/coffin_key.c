//  Khojem
//  coffin key 
#include <std.h>

inherit OBJECT;
 
void create() {
  ::create();
    set_name("coffin_key");
    set_id( ({ "coffin_key", "key" }) );
    set_short("coffin key");
    set_long("A brass key with many ornate runes.\n");
    set_weight(10);
    set_value(0);
}

