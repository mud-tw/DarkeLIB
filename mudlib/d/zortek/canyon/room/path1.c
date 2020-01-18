// Entry to Muerta Canyon
// Created by Zortek
// 031596

#include <std.h>
#include "/d/zortek/canyon/canyon.h"

inherit ROOM;

int no_exit() { return 1;}
int block_exit() {
   if(wizardp(this_player())) return 0;
   if(this_player()->query_ghost()) return 0;
   if(present("mane", this_object())) {
     write("%^B_RED%^A devil blocks your path down.%^RESET%^");
     return 1;
   }
   return 0;
}

void init() {
    ::init();
    if(this_player()->is_player() ||
       this_player()->is_pet() ) {
      add_action("block_exit", "down");
      add_action("block_exit", "up");
    }
//   if(this_player()->query_property("zor_mon")) {
//    add_action("no_exit","up");
//  }
    if(this_player()->query_property("mane sentry")) {
      add_action("no_exit","down");
    }
}

void reset() {
   object ob;
   int x = random(8)+4;
    ::reset();
   if(!present("mane", this_object()) ) {
     while(x--) {
      ob = new(MON+"mane.c");
      ob->set("short", "Sentry Mane");
      ob->set_level(5);
      ob->set_max_hp(700);
      ob->set_hp(700);
      ob->set_property("mane sentry", 1);
      ob->move(this_object());
     }
   }
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 0);
    set_property("night light",0);
    set("short", "Entry Path of Muerta Canyon");
    set("day long", @DAY
This is a narrow path steeply cut into a wall of Muerta Canyon.
The light of day is greatly dimmed by the massive shadows cast
by the walls rising at your sides.
DAY
   );
    set("night long", @NIGHT
This is a narrow path steeply cut into the wall of Muerta Canyon.
Very little lunar light filters into this area because of the great
shadows cast by the massive walls rising at your sides.
NIGHT
    );
    add_exit(ROOMS+"entry", "up");
      add_exit(ROOMS+"path2", "down");
    set_items(([
    "path": "This path is an unremarkable, dirt path.",
    ({ "canyon", "walls", "wall" }): @CANYON
The canyon appears to be a river-cut land deformation.  The walls
seem to be comprised mainly of sandstone with occational layers
of limestone visible.
CANYON
,
    ]));
    set_smell("default", "There is a certain scent of decay in the air.");
    set_listen("default", "It is strangely quiet.");
   reset();
}
