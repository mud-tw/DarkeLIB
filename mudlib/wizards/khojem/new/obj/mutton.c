//  Wizard:  Khojem
//  Mutton
//  mutton.c
 
#include <std.h>

inherit "/std/food";

 
void create() {
  ::create();
    set_name("mutton");
    set_id( ({ "mutton", "meat", "sheep" }) );
    set_short("chunk o' mutton");
    set_long("A large chunk of cooked sheep meat.");
    set_weight(25);
    set_strength(50);
    set_float_value(10.0);
    return;
}
