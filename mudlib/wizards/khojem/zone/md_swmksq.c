//      Wizard:  Khojem
//      MD-southwest market square
//      md_swmksq.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "Southwest Market Square");
    set("long", "You are in the southwest corner of the market square.  "+
      "A rough, hewned stone courtyard stretches out before you.  "+
      "In the distance you can see numerous Sword-demon commoners rushing "+
      "about on their various daily chores.  Even now while they carry out "+
      "these otherwise mundate chores you sense a determination in their "+
      "daily endeavors.  This market square is unkept and filth is everywhere.  "+
      "The decayed remains of battle-hacked foreigners are everywhere.  "+
      "You sense you are not a welcome traveller in these parts. "+
      "To the south you see the entrance to a shop of some type."
  );
    add_exit("md_wmksq","north");
    add_exit("md_smksq","east");
    add_exit("md_gshop","south");
    set_items(([
      "shop" : "It appears to be a shop."
      ]));
    set_smell("default", "A horrible, rotten smell permeates the air.");
    set_listen("default", "All around you are the sounds of slow dripping water.");
}

