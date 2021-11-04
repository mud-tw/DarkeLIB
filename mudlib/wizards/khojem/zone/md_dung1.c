//      Wizard:  Khojem
//      Dungeon Room 1
//      md_dung1.c

#include <std.h>

inherit ROOM;

void create() {
    int i;
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "Dungeon");
    set("long", 
      "You find yourself in the Donjon's Dungeon.  The floor and "+
      "walls are masoned in large stone blocks.  "+
      "It is dark and the air is damp and musty.  "+
      "Stairs lead up into the Donjon and the hallway leads east into "+
      "darkness.  You feel uneasy down here and consider retreat."
   );
    set_items(([
      ({ "stones", "blocks", "stone", "block", "floor" }) :
        "The stone is rough and damp to the touch.  "+
        "It looks like these stones have been here since the beginning "+
        "of time.  They are large, massive stones.",
      ({ "stairs","stair" }) :
        "A series of stone masonery steps lead up into the Donjon.",
      ({ "hallway", "hall" }) :
        "The hall is dark and sinister looking.",
        "rat"  :  "You spot a rat running away from you."
      ]));
    add_exit("md_donjon1","stairs");
    add_exit("md_dung2","east");
    set_smell("default", "A horrible, rotten smell permeates the air.");
    set_listen("default", "You hear a rats clawed paws nearby.");
}
