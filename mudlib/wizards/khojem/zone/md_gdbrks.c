//      Wizard:  Khojem
//      Guard Barracks
//      md_gdbrks.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "Guard Barracks");
    set("long", "You are in the Guard Barracks. "+
      "It isn't much for comfort.  The dirt ground is covered "+
      "with several straw mattresses.  An archway is leads out "+
      "on the north wall."
   );
   add_exit("md_yard","north");
   add_exit("md_gdroom","east");
      set_items(([
      ({ "mattress", "mattresses" }) : 
        "They look uncomfortable.  With all the ticks you would "+
        "not sleep a soundly.",
      ({ "dirt", "ground", "floor" }) : 
        "The floor is a slippery, hard mud from constant use.",
      ({ "arch", "archway" }) : 
        "The archway leads out to a practice yard.",
      ({ "wall", "walls" }) :
        "The wall is poorly constucted and water is leaking in."
      ]));
   set_smell("default", "A horrible, rotten smell permeates the air.");
   set_listen("default", "All around you are the sounds of slow dripping water.");
}
