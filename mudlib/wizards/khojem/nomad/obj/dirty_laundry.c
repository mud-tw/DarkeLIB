//  Wizard:  Khojem
//  dirty laundry
//  dirty_laundry.c
 
#include <std.h>

inherit OBJECT;
 
void create() {
  ::create();
    set_name("dirty_laundry");
    set_id( ({ "dirty laundry", "laundry" }) );
    set_short("some dirty laundry");
    set_long("Now this is gross!  The dirty laundry is filty and "+
      "teeming with lice.");
    set_weight(50);
    set_value(0);
}
