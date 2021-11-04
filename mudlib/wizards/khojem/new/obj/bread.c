//  Wizard:  Khojem
//  Wayfarer's Bread
//  bread.c
 
#include <std.h>

inherit "/std/food";

 
void create() {
  ::create();
    set_name("wayfarer's bread");
    set_id( ({ "bread", "loaf", "loaf of bread", "wayfarer's bread" }) );
    set_short("wayfarer's bread");
    set_long("A long, dark-brown bread specially baked "+
      "for long-term freshness.");
    set_weight(8);
    set_strength(20);
    set_float_value(4.0);
    return;
}
