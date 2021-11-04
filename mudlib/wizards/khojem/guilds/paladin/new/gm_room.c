//      Wizard:  Khojem
//      Paladin Guildmaster's Room
//      gm_room.c

#include <std.h>

inherit ROOM;

void create() {
  object ob;
    ::create();
  set_property("light", 3);
  set_property("indoors", 1);
  set("short", "Paladin Guildmaster's Room");
  set("long", 
    "This is the room where the Paladin Guildmaster "
    "carrys out the many tasks needed to run the guild.  "
    "The room is simple and unadorned.  It refects the "
    "chastened life of the guildmaster.\n" 
  );
  add_exit("/d/damned/guilds/paladin/meeting","northeast");
}

