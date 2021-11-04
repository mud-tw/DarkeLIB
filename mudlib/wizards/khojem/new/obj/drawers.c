//  Wizard:  Khojem
//	chest of drawers
//	drawers.c

inherit "/std/bag_logic";

void create() {
    object money;
    ::create();
    set_id( ({"chest", "drawers", "wooden chest"}) );
    set_name("chest");
    set("short", "chest of drawers");
    set("long", "A huge, wooden chest of drawers.\nIt is closed.");
    set_open_long("A huge, wooden chest of drawers.\nIt is open.");
    set_closed_long("A huge, wooden chest of drawers.\nIt is closed.");
    set_weight(9000);
    set_value(1000);
    set_max_internal_encumbrance(2000);
    set_possible_to_close(1);
    money = new("std/obj/coins");
    money->set_money("gold", random(100));
    money->move(this_object());
    toggle_closed(this_object());
}
