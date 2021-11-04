//	An example skill training room for the paladin's guild.
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95

inherit "/std/guilds/skill_room";

void create() {
  ::create();
  set("short", "The Paladins' Training Room");
  set("long", 
    "In this broad room the paladins hone their great skills.  "
    "You see a few wooden dummies used for practice.  The clanging "
    "sound of metal against metal is a constant sound here.  The "
    "stone walls of the training room seem to amplify the sound.\n"
  );
//  "\n" important here, too.

  set_property("light", 2);
  set_property("indoors", 1);
  
  //  The following line is VERY, VERY important.
  set_join_room("/d/damned/guilds/join_rooms/paladin_join");

  add_exit("/d/damned/guilds/paladin/meeting", "north");
  
  //  All the rest is adding the skills.  The add_skill lines are of the
  //  following form:
  //  	add_skill(string skill, int level, int flag)
  //	skill 		The name of the skill which is being added
  // 	level		The level at which the player may begin
  //			developing the skill.
  //	flag		(optional)  If a non-zero number is supplied,
  //			the skill will be considered "secondary" to
  //			the guild and cost double to develop.

  add_skill("blade", 1);
  add_skill("consider", 1);
  add_skill("swimming",1);
  add_skill("concentrate", 3);
  add_skill("offhand training", 5);
  add_skill("dual attack", 12);
  add_skill("two handed blade", 1);
  add_skill("attack", 1);
  add_skill("melee", 1);
  add_skill("parry", 1);
  add_skill("block", 1);
  add_skill("blunt", 1);
  add_skill("lay on hands", 1);
  add_skill("prospecting", 1, 1);
  add_skill("two handed blunt", 1);
  add_skill("flail", 1);
  add_skill("two handed flail", 1);
  add_skill("axe", 1);
  add_skill("two handed polearm", 1);
  add_skill("perception", 1);
  add_skill("swimming", 1);
  add_skill("body block", 3);
  add_skill("reverse stroke", 13);
  add_skill("compare", 3);
  add_skill("dodge", 3);
  add_skill("prayer", 3);
  add_skill("body alteration", 4);
  add_skill("trade lore", 1, 1);
  add_skill("communion", 7);
  
  return;
}

