//      Wizard:  Khojem
//      MD-alley2
//      md_alley2.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "Alley");
    set("long", "You stand in a damp, dirty alley.  Its narrow "+
      "walls close in around you and make you feel uncomfortable."
  );
    add_exit("md_house3","north");
    add_exit("md_house4","south");
    add_exit("md_alley1","west");
    set_smell("default", "A horrible, rotten smell permeates the air.");
    set_listen("default", "All around you are the sounds of slow dripping water.");
}

