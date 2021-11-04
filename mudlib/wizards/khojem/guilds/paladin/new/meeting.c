//      Wizard:  Khojem
//      Paladin Meeting Room
//      meeting.c

#include <std.h>

inherit ROOM;


void reset() {
  ::reset();
  if(!present("guard")) new("/d/damned/guilds/paladin/t_guard")->
	move(this_object());
  return;
}

 
void create() {
  object ob;
    ::create();
  set_property("light", 3);
  set_property("indoors", 1);
  set("short", "Paladin Meeting Room");
  set("long", 
    "This is a large vaulted meeting room that guild members use "
    "to gather and discuss issues relative to the guild.  The "
    "floor is constructed of marble and inlayed with an alternating "
    "sequence of white crosses against a black offset.  The walls "
    "are lined with shields bearing the coat of arms of paladins "
    "who are now legends in our time.\n" 
  );
  add_exit("/d/damned/guilds/join_rooms/paladin","northeast");
  add_exit("/d/damned/guilds/paladin/parapet","stairs");
  add_exit("/d/damned/guilds/paladin/meditation","east");
  add_exit("/d/damned/guilds/paladin/p_treas","down");
  add_exit("/d/damned/guilds/paladin/train_room","south");
  add_exit("/d/damned/guilds/paladin/gm_room","southwest");
  add_exit("/d/damned/guilds/paladin/paladin_spell_room","west");
  set_items(([
    ({ "floor", "marble floor" }) :
       "The marble floor is finely crafted of white marble in the "
       "shape of a cross against a contrasting black marble backdrop.  "
       "The contrast brings to mind the constrast between good and "
       "evil.",
    ({ "wall", "shields" }) :
       "The wall is constructed of heavy stone blocks and hanging "
       "from them are a number of large shields that bear the "
       "coat of arms of past paladins who gave thier live for the "
       "pursuit against evil.  Many of the shields are dented and "
       "fire scorched.  They are a testament of the violent battles "
       "the bearers suffered." ,
  ]));
  ob = new("std/bboard");
  ob->set_name("board");
  ob->set_id( ({"board", "paladin_board"}) );
  ob->set_board_id("paladin_board");
  ob->set_max_posts(25);
  ob->set_location("d/damned/guilds/paladin/meeting");
  ob->set("short","Paladin Board");
  ob->set("long","A board for players to post notes.\n");
}

