//      Wizard:  Khojem
//      Donjon Room 4
//      md_donjon4.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "Castle's Donjon");
    set("long", 
      "You are on the stairs in the donjon.  "+
      "The stairs lead up and down from here."
   );
    set_items(([
      ({ "stairs","stair" }) :
        "A series of stone masonery steps lead up and down.",
       ]));
    add_exit("md_donjon3","down");
    add_exit("md_donjon5","up");
    set_smell("default", "A horrible, rotten smell permeates the air.");
    set_listen("default", "The wind blowing is howling down from above.");
}
