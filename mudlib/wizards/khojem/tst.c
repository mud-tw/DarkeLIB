
#include <std.h>

inherit MONSTER;

void init() {
::init();
   force_me("use concentrate");
   force_me("use focus of elements at ice");
return;
}

void create() {
object ob;
 ::create();
   set_name("frost demon");
   set("id",({"demon","frost demon"}));
   set_level(15);
   set_short("Frost Demon");
   set("long",
   "forthcoming\n");
   set("race","demon");
   set_gender("male");
   set_body_type("human");
   set_overall_ac(18);
   set("melee damage",([
     "cutting" : 20,
     "crushing" : 15,
     "cold" : 30,
     ]));
   set_fingers(6);
   set_moving(0);
   set_speed(0);
   set_max_hp(1500);
   set_hp(1500);
   set_max_mp(2000);
   set_mp(1500);
   set_exp(15000);
   set("aggressive",0);
   set_wimpy(0);
   set_stats("intelligence", 127);
   set_stats("strength", 133);
   set_stats("constitution", 150);
   set_stats("dexterity", 104);
   set_casting_chance(25);
   set_combat_chance(25);
   add_spell("elemental shield", "$ME");
   add_spell("elemental bolt", "$A");
   set_spell_level("elemental shield",4);
   set_spell_level("elemental bold", 3);
   set_skill("melee", "150");
   set_skill("attack", "100");
   set_skill("cold lore", "100");
   set_skill("ice lore", "100");
   set_skill("fire lore", "25");
   set_skill("dodge", 75);
   set_skill("resist stun", 81);
   set_skill("reverse stroke", 73);
   set_skill("perception", 93);
   set_skill("focus of elements", 200);
   set_skill("concentrate", 56);
   set_skill("whirlwind attack", 88);
   set_skill("elementalism", 123);
}

