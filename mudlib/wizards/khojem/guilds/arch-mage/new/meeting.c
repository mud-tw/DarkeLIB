//      Wizard:  Khojem
//      Arch-Mage Meeting Room
//      meeting.c

#include <std.h>

inherit ROOM;

void create() {
  object ob;
    ::create();
  set_property("light", 3);
  set_property("indoors", 1);
  set("short", "Arch-Mage Meeting Room");
  set("long", 
    "This is a large meeting room at the base of a circular tower.
    "The guild members use this room "
    "to gather and discuss issues relative to the guild.  The "
    "floor and walls constructed of rough hewned basalt blocks.\n" 
  );
  add_exit("/d/damned/guilds/join_rooms/arch-mage","east");
  add_exit("/d/damned/guilds/arch-mage/train_room","down");
  add_exit("/d/damned/guilds/arch-mage/arch-mage_spell_room","up");
  set_items(([
    ({ "floor", "wall", "walls", "basalt blocks" }) :
       "The walls are unadorned.  The large blocks of basalt that "
       "are fitted to form the walls and floor appear old.  This "
       "tower appears to be eons old.",
  ]));
  ob = new("std/bboard");
  ob->set_name("board");
  ob->set_id( ({"board", "arch-mage_board"}) );
  ob->set_board_id("arch-mage_board");
  ob->set_max_posts(25);
  ob->set_location("d/damned/guilds/arch-mage/meeting");
  ob->set("short","Arch-Mage Board");
  ob->set("long","A board for Arch-Mages to post notes.\n");
}

