//  Wizard:  Khojem
//  pirate's chest
//  pchest.c
 
#include <std.h>

inherit "/std/bag_logic";

void create() {
  object obj;
  ::create();
    set_name("chest");
    set_id( ({ "chest", "iron chest" }));
    set_short("iron chest");
    set_long("A heavy, reinforced iron chest is longer than a man is tall.  "+
      "It has a heavy lock on it and large plates to reinforce the seams."
    );
    set_value(1);
    set_weight(99999);
    set_max_internal_encumbrance(600);
    set_possible_to_close(1);
    set_key("pirate_captain_key");
    obj=new("std/obj/coins");
    obj->set_money("mithril",(random(99)+100));
    obj->move(this_object());
    toggle_closed();
    set_lock("locked");
    set_lock_level(45);
    set_trap_func("/wizards/diewarzau/obj/misc/trap_func","fire_trap");
    set_trap_level(20);    
    return;
}

