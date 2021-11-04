// Wizard:  Khojem
// DarkeMud Quality Control Board Room

inherit ROOM;

void create() {
    object ob;
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "Quality Control Room");
    set("long","Wizards communicate DarkeMud standards on area design.");
    ob = new("/std/bboard");
    add_exit("/d/standard/adv_main", "hall");
    ob->set_name("board");
    ob->set_id( ({ "board", "Quality Control Board" }) );
    ob->set_board_id("QC");
    ob->set_max_posts(30);
    ob->set_location("/wizards/khojem/QC/QC");
    ob->set("short", "the DarkeMud QC Board");
    ob->set("long", "Used to communicate DarkeMud standards for area
design.\n");
}
