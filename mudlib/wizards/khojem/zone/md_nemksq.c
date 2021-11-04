//      Wizard:  Khojem
//      MD-northeast market square
//      md_nemksq.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "Northeast Market Square");
    set("long", "You are in the northeast corner of a market square.  "+
      "A rough, hewned stone courtyard stretches out before you.  "+
      "In the distance you can see numerous Sword-demon commoners rushing "+
      "about on their various daily chores.  Even now while they carry out "+
      "these otherwise mundate chores you sense a determination in their "+
      "daily endeavors.  This market square is unkept and filth is everywhere.  "+
      "The decayed remains of battle-hacked foreigners are everywhere.  "+
      "You sense you are not a welcome traveller in these parts."
  );
    add_exit("md_nmksq","west");
    add_exit("md_emksq","south");
    set_smell("default", "A horrible, rotten smell permeates the air.");
    set_listen("default", "All around you are the sounds of slow dripping water.");
}
