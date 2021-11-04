//      Wizard:  Khojem
//      Rogue's Hideout
//      md_hideout.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "Rogue's Hideout");
    set("long", "You fall into a heap in a dark, Rogue's Hideout."+
      "You suspect they will not be happy to find you in this secret place."
  );
    add_exit("md_alley4","out");
    set_smell("default", "A horrible, rotten smell permeates the air.");
    set_listen("default", "All around you are the sounds of slow dripping water.");
}

