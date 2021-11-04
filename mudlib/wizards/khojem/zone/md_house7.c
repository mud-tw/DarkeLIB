//      Wizard:  Khojem
//      MD-house7
//      md_house7.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "A small home");
    set("long", "Ahh.. what a mess!  This place is a shambles.  "+
      "All around is filth.  A combination of common household items "+
      "and body parts is everywhere.  The room has no furniture "+
      "and the ceiling leaks."
  );
    add_exit("md_alley4","south");
    set_smell("default", "A horrible, rotten smell permeates the air.");
    set_listen("default", "All around you are the sounds of slow dripping water.");
}
