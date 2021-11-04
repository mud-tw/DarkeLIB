//      Wizard:  Khojem
//      causeway
//      md_way.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "City Causeway");
    set("long", "The square has narrowed to a dark, wide causeway.  "+
      "The cobblestones here are worn smooth and the dampness lessens "+
      "your footing.  You feel uneasy even in these broad confines."
  );
    add_exit("md_smksq","north");
    add_exit("md_plguard","west");
    add_exit("md_donjon1","east");
    add_exit("md_ncommon","south");
    set_smell("default", "A horrible, rotten smell permeates the air.");
    set_listen("default", "All around you are the sounds of slow dripping water.");
}
