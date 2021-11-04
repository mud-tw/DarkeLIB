//  Wizard:  Khojem
//  coffin
//  coffin.c
 
#include <std.h>

inherit "/std/bag_logic";

void create() {
  object obj;
  ::create();
    set_name("wooden coffin");
    set_id( ({ "coffin", "wooden coffin" }));
    set_short("a wooden coffin");
    set_long("A heavy wooden coffin rests here.  Its wood has petrified from "+
      "years of exposure to the salt air.  Large brass bolts secure the lid."
    );
    set_value(0);
    set_weight(10000);
    set_max_internal_encumbrance(100);
    set_possible_to_close(1);
    set_key("coffin_key");
    set_trap_level(10);
    obj=new("std/obj/coins");
    obj->set_money("mithril",(random(10)+5));
    obj->move(this_object());
    return;
}
