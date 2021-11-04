//      Wizard:  Khojem
//      MD-north market square
//      md_nmksq.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "North Market Square");
    set("long","You stand at the northedge of a market place.  "+
      "A rough, hewned stone courtyard stretches out before you.  "+
      "In the distance you can see numerous Sword-demon commoners rushing "+
      "about on their various daily chores.  Even now while they carry out "+
      "these otherwise mundate chores you sense a determination in their "+
      "daily endeavors.  This market square is unkept and filth is everywhere.  "+
      "The decayed remains of battle-hacked foreigners are everywhere.  "+
      "You sense you are not a welcome traveller in these parts."
  );
    set_exits( ({ "md_gdroom","md_nwmksq","md_nemksq","md_cmksq"}),
      ({ "north","west","east","south" })
    );
    set_smell("default", "A horrible, rotten smell permeates the air.");
    set_listen("default", "All around you are the sounds of slow dripping water.");
}

