//   Khojem
//   Sentry 2
//   sentry2.c


#include <std.h>

inherit MONSTER;

create() {
	::create();
	set_name("sentry");
	set("id", ({ "guard", "sentry" }) );
	set_level(9);
	set("short", "sentry");
	set("long",
		"A large sentry bars your way."
	);
	add_money("gold", random(350));
	set_alignment(0);
	set("race", "sword-demon");
	set_gender("male");
	set_body_type("human");
	set_overall_ac(10);
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	set_skill("melee", 30);
	set_skill("attack", 40);
	set_skill("two handed polearm", 40);
	set_wimpy(20);
	set_wimpydir("east");
	set("aggressive", 1);
	set_languages("Yin");
	set_emotes(5, ({ 
	  "The sentry laughs at you.",
	  "The sentry spits on the floor.  He just lost a few teeth."
	}),1);
	set_speech(10,"Yin",({ 
	  "Get out of my dungeon!",
	  "I will feed your corpse to my pet rat!",
	  "You are too slow!",
	  "I will piss in your dead skulls!"
	}),1);
	new("/wizards/khojem/zone/weapon/halberd")->move(this_object());
	force_me("wield halberd in right hand and left hand");
	new("/wizards/khojem/zone/armor/glove")->move(this_object());
	force_me("wear glove on right hand");
}
