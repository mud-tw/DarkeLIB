//	An example skill training room for the fighter's guild.
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95
//  reworked by Khojem 10/22/96

inherit "/std/guilds/skill_room";

void create() {
  ::create();
  set("short", "The Arch Mage's Training Room");
  set("long", 
    "This is the room where arch-magi come to hone their skills, whether they "
    "be in spellcasting or combat.  Several advanced arch-magi lurk about "
    "waiting for students.\n"
  );
  //  "\n" important here, too.

  set_items(([ "arch-magi" : "They are clothed in ornate robes." ]));

  set_property("light", 2);
  set_property("indoors", 1);
  
  //  The following line is VERY, VERY important.
  set_join_room("/d/damned/guilds/join_rooms/arch-mage_join");

  set_exits( ([ "up" : "/d/damned/guilds/arch-mage/meeting",
	     "down" : "/d/damned/guilds/arch-mage/am_treas" ]));

  //  All the rest is adding the skills.  The add_skill lines are of the
  //  following form:
  //  	add_skill(string skill, int level, int flag)
  //	skill 		The name of the skill which is being added
  // 	level		The level at which the player may begin
  //			developing the skill.
  //	flag		(optional)  If a non-zero number is supplied,
  //			the skill will be considered "secondary" to
  //			the guild and cost double to develop.

  add_skill("knife", 1);
  add_skill("prospecting", 1, 1);
  add_skill("concentrate", 5, 1);
  add_skill("two handed staff", 1);
  add_skill("magery", 1);
  add_skill("conjuration", 1);
  add_skill("illusionism", 1);
  add_skill("sorcery", 6);
  add_skill("focus casting", 1);
  add_skill("fast casting", 5);
  add_skill("detect magic", 5);
  add_skill("spell sense", 12);
  add_skill("perception", 1, 1);
  add_skill("dodge", 5, 1);
  add_skill("swimming",1);
  add_skill("consider", 1);
  add_skill("attack", 1);
  add_skill("melee", 1, 1);
  add_skill("trade lore", 1, 1);
  add_skill("telepathy", 15, 1);
  return;
}

void reset() {
  if(!present("guard"))
    new("/d/damned/guilds/arch-mage/t_guard")->move(this_object());
  return;
}

