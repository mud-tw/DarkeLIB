//  Wizard:  Khojem
//  Berries
//  berries.c
 
#include <std.h>

inherit "/std/food";

 
void create() {
  ::create();
    set_name("berries");
    set_id( ({ "berries" }) );
    set_short("bunch of berries");
    set_long("A big bunch of berries dripping in morning dew.");
    set_weight(4);
    set_strength(10);
    set_float_value(2.0);
    return;
}
