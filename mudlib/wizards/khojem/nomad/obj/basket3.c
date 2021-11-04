//  Wizard:  Khojem
//  woven basket3
//  basket3.c
 
#include <std.h>

inherit "/std/bag_logic";

void create() {
  object obj;
  ::create();
    set_name("basket3");
    set_id( ({ "basket", "woven basket" }));
    set_short("a sturdy, wooden chest");
    set_long("A large round basket made from the reeds that grow "+
      "wild near the oasis.  The reeds are dried and bleached white "+
      "by the hot desert sun.  The basket stands a few feet high and "
      "has a matching cover that fits securely on top.");
    set_value(8);
    set_weight(580);
    set_short("A large, woven basket");
    set_max_internal_encumbrance(300);
    set_possible_to_close(1);
    return;
}

