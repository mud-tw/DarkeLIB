//  Khojem
//  Monster:  Morty the Shopkeeper
//  File:     morty.c

#include <std.h>

inherit "/std/npc_shop";


void reset() {
   ::reset();
this_object()->set_money("gold",1000);
}

void init() {
	::init();
	say( query_money("gold") );
}

create() {
  ::create();
    set_name("morty");
    set_id( ({ "morty", "vendor", "shop keeper", "keeper", "shopkeeper" }) );
    set_level(5);
    set_short("Morty the shopkeeper stands here");
    set_long("Morty is an elderly Sword-demon.  "+
      "It appears he has run this shop for some time now."
      );
    set("race", "sword-demon");
    set_gender("male");
    set_body_type("human");
    set_stats("intelligence", 100);
    set_property("melee damage", ([ "crushing" : 10]));
    set_skill("melee", 10);
    set_skill("dodge", 10);
    set_skill("parry", 10);
    set_stats("dexterity", 20);
    set_max_hp(50);
    set_hp(50);
    set_speed(9999999);
    set_moving(0);
    set("storage room","/wizards/khojem/zone/md_gshop_storage");
    set("markup",150);
    set_languages( ({"common"}) );
    set_lang_prof("yin",9);
    set_lang_prof("undead",9);
    set_skill("bargaining", 100);
    add_money("gold", (2000 + random(200)));
}
