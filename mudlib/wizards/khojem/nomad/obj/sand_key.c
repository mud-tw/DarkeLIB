//  Wizard:  Khojem
//  sand Key
//  sand_key.c
 
#include <std.h>

inherit OBJECT;
 
void create() {
  ::create();
    set_name("sand key");
    set_id( ({ "sand key", "key" }) );
    set_short("sand key");
    set_long("A small key made entirely from carved sandstone.\n");
    set_weight(1);
    set_value(0);
}
