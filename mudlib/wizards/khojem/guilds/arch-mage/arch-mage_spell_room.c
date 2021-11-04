//	An example skill training room for the fighter's guild.
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95

inherit "/std/guilds/spell_room";

void create() {
  ::create();
  set("short", "The Arch Mage's Spell Training Room");
  set("long", 
"This room is a vast library.  Here, the arch-magi study their various "
"spells.\n");
  //  "\n" important here, too.

  set_property("light", 2);
  set_property("indoors", 1);
  
  //  The following line is VERY, VERY important.
  set_join_room("/d/damned/guilds/join_rooms/arch-mage_join");

  set_exits( ([ "west" : "/d/damned/guilds/arch-mage/train_room" ]) );
  //  All the rest is adding the spells.  The add_skill lines are of the
  //  following form:
  //  	add_spell(string spell, int level, int flag)
  //	spell 		The name of the spell which is being added
  // 	level		(optional) The level at which the player may begin
  //			developing the spell.  If not supplied,
  //			the default level is used.
  //	flag		(optional)  If a non-zero number is supplied,
  //			the skill will be considered "secondary" to
  //			the guild and cost double to develop.

   add_spell("awareness");
  add_spell("burning hands");
  add_spell("fireball");
  add_spell("magic missile");
  add_spell("explosive fireball");
  add_spell("lightning bolt");
  add_spell("haste");
  add_spell("see invisible");
  add_spell("killing cloud");
  add_spell("meteor storm");
  add_spell("dispel magic");
  add_spell("internal flame");
  add_spell("ice dagger");
  add_spell("blizzard");
  add_spell("power word, blind");
  add_spell("power word, stun");
  add_spell("shocking grasp");
  add_spell("power word, kill");
  add_spell("link");
  add_spell("anti-magic aura");
  add_spell("store spell");
  add_spell("delay");
  add_spell("mana drain");
  add_spell("vacuum bolt");
  add_spell("dranaxar's anti-magic field");
  add_spell("levitation");
  add_spell("light");
  add_spell("darkness", 1);
  add_spell("clairvoyance");
  add_spell("faerie fire", 1);
  add_spell("dark vision");
  add_spell("blur");
  add_spell("mirror image");
  add_spell("counter spell");
  add_spell("invisibility");
  add_spell("summon familiar");
  add_spell("summon greater familiar");
  add_spell("stabilize familiar");
  add_spell("summon");
  add_spell("transport");
  add_spell("scry", 12);
  add_spell("call lightning");
  add_spell("teleport");
  add_spell("create teleport beacon");
  add_spell("fire shield");
  return;
}

  
