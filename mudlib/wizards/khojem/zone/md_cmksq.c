//      Wizard:  Khojem
//      MD-center market square
//      md_cmksq.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "Sword-Demon Market Square");
    set("long", "You are in the center of the Sword-demon market square.  "+
      "A rough, hewned stone courtyard stretches out before you.  "+
      "In the distance you can see numerous Sword-demon commoners rushing "+
      "about on their various daily chores.  Even now while they carry out "+
      "these otherwise mundate chores you sense a determination in their "+
      "daily endeavors.  This market square is unkept and filth is everywhere.  "+
      "The decayed remains of battle-hacked foreigners are everywhere.  "+
      "You sense you are not a welcome traveller in these parts.\n"
      "Here at the square's center is a large fountain in the shape of "+
      "a serpent."
  );
    set_items(([
     ({ "serpent", "worm", "fountain", "center", "shape" }) :
      "Now that you examine the fountain's sculpture more "+
      "closely you realize that the serpent is really a worm.  "+
      "The worm looks disgusting, but the water appears clean "+
      "fresh."
     ]));
    set_exits( ({ "md_emksq","md_nmksq","md_wmksq","md_smksq"}),
      ({ "east","north","west","south" })
    );
    set_smell("default", "A horrible, rotten smell permeates the air.");
    set_listen("default", "All around you are the sounds of slow dripping water.");
}
