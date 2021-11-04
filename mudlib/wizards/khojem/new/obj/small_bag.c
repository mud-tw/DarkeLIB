//  Wizard:  Khojem
//  small bag
//  small_bag.c
 
inherit "/std/bag_logic";

void create() {
    ::create();
    set_id( ({ "small bag", "bag" }) );
    set_name("bag");
    set("short", "A small bag");
    set("long", "A small cloth bag with drawstring.\nIt is closed.");
    set_open_long("A small cloth bag with drawstring.\nIt is open.");
    set_closed_long("A small cloth bag with drawstring.\nIt is closed.");
    set_weight(10);
    set_value(30);
    set_max_internal_encumbrance(100);
    set_possible_to_close(1);
}

