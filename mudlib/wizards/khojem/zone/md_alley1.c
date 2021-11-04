//      Wizard:  Khojem
//      MD-alley1
//      md_alley1.c

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
    add_exit("md_emksq","west");
    add_exit("md_house1","north");
    add_exit("md_house2","south");
    add_exit("md_alley2","east");
    set_smell("default", "A horrible, rotten smell permeates the air.");
    set_listen("default", "All around you are the sounds of slow dripping water.");
}
