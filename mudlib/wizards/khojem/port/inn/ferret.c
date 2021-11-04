// Khojem
// locksmith
// ferret.c

#include <std.h>

inherit MONSTER;

create() {
  ::create();
    set_name("ferret");
    set_id( ({ "locksmith", "ferret" }) );
    set_short("Ferret, the Vo'Sangor Locksmith");
    set("race", "halfling");
    set_long(
    "Ferret was tinkering with a lock, but was distracted when you entered.");
    set_body_type("human");
    set_hp(200000);
    set_max_hp(200000);
   set_property("enhance criticals", -10);
    set_level(10);
    set_exp(1000000);
    set_property("melee damage", ([ "crushing" : 99]));
    set_skill("melee", 260);
    set_skill("elementalism", 175);
    set_spell_level("elemental storm", 6);
    add_spell("elemental storm", "");
    set_combat_chance(80);
    set_skill("dodge", 70);
    set_skill("parry", 20);
    set_stats("dexterity", 130);
}
int query_num_rounds() { return 3; }

string query_element() { return "vacid"; }


