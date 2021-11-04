//      Wizard:  Khojem
//      Arch-Mage GM's Office
//      gm-room.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
  set_property("light", 3);
  set_property("indoors", 1);
  set("short", "Arch-Mage Guildmaster's Office");
  set("long", 
    "This is the Guildmaster's Office.  Here the guildmaster carries "
    "out the important duties of running the guild.  The has bare "
    "stone walls and no furniture.\n" 
  );
  add_exit("/d/damned/guilds/arch-mage/arch-mage_spell_room","down");
  add_exit("/d/damned/guilds/arch-mage/tower-top","up");
  set_items(([
    ({ "floor", "wall", "walls", "basalt blocks" }) :
       "The walls are unadorned.  The large blocks of basalt that "
       "are fitted to form the walls and floor appear old.  This "
       "tower appears to be eons old.",
  ]));
}

