//  Khojem
//  Monster:  Gate Sentry
//  File:     ksentry.c

#include <std.h>

inherit MONSTER;

create() {
  ::create();
    set_name("gate sentry");
    set_id( ({ "sentry","guard","gate sentry" }) );
    set_level(5);
    set_short("Gate Sentry");
    set_long("A sentry stands here protecting the gates to "+
      "the city from travellers and bandits from beyond its "+
      "protected walls.  You are a foreigner and obviously "+
      "not a welcome sight."
      );
    set("race", "sword-demon");
    set_gender("male");
    set_body_type("human");
    set_overall_ac(4);
    set_wielding_limbs( ({ "right hand", "left hand" }) );
    set_skill("melee", 10);
    set_skill("dodge", 10);
    set_skill("parry", 10);
    set_skill("two handed polearm", 30);
    set_wimpy(0);
    set("aggressive",1);
	set_languages("Yin");
	set_money("gold",random(30));
	set_alignment(0);
	set_emotes(5, ({
	  "The sentry lunges at you."
	  "The sentry pants from his exursion."}),1);
	set_speech(10,"Yin",({ 
	  "Foreigners are not allowed within the city walls!",
	  "Go away!  You scum.",
	  "To the gate!  To the gate!  We are under attack from bandits!",
	  "You'll never get by me!",
	  "I will die before I let scum like you within my city!"
	}),1);
    new("/wizards/khojem/zone/weapon/halberd")->move(this_object());
	force_me("wield halberd in right hand and left hand");
	new("/wizards/khojem/zone/obj/sentry_gate_key")->move(this_object());
}
