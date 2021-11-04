//  Khojem
//	drawers.c
//	a chest of drawers

inherit "/std/bag_logic";

void create() {
    object money;
    ::create();
    set_id( ({"chest", "drawers", "wooden chest"}) );
    set_name("chest");
    set("short", "chest of drawers");
    set("long", "A huge, wooden chest.\nIt is closed.");
    set_open_long("A huge, wooden chest.\nIt is open.");
    set_closed_long("A huge, wooden chest.\nIt is closed.");
    set_no_clean(1);
    set_weight(9000);
    set_value(1000);
    set_max_internal_encumbrance(2000);
    set_possible_to_close(1);
    money = new("std/obj/coins");
    money->set_money("platinum", random(5));
    money->set_money("gold", random(100));
    money->set_money("electrum", random(500));
    money->set_money("silver", random(1000));
    money->set_money("copper", random(100));
    money->move(this_object());
}

