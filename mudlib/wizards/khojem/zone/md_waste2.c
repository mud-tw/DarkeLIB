//      Wizard:  Khojem
//      MD-Zone Wastelands 2
//      md_waste2.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",-2);
    set_property("indoors", 1);
    set_property("no teleport",1);
    set_property("no magic",1);
    set("short", "Wastelands");
    set("long", "All about you is darkness in these Wastelands.  Your footing "+
      "is sound, but you can't see any landmarks or path about you."
   );
    add_exit("md_waste2","south");
    add_exit("md_waste1","north");
    add_exit("md_waste1","west");
    add_exit("md_entry","east");
    set_invis_exits(({"north","south","west","east"}));
    set_smell("default", "A horrible, rotten smell permeates the air.");
    set_listen("default", "All around you are the sounds of slow dripping water.");
}

