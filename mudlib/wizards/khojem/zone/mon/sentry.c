//   Khojem
//   Sentry
//   sentry.c


#include <std.h>

inherit MONSTER;

create() {
	::create();
	set_name("sentry");
	set("id", ({ "guard", "sentry" }) );
	set_level(6);
	set("short", "sentry");
	set("long",
		"A poorly armed sentry."
	);
	add_money("gold", random(20));
	set_alignment(0);
	set("race", "sword-demon");
	set_gender("male");
	set_body_type("human");
	set_overall_ac(15);
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	set_skill("melee", 20);
	set_skill("attack", 30);
	set_skill("two handed polearm", 40);
	set_wimpy(0);
	set("aggressive", 1);
	set_languages("Yin");
	set_emotes(5, ({ 
	  "This sentry wants to chop your head off.",
	  "The sentry spits in your face.  He had gruel for lunch."
	}),1);
	set_speech(10,"Yin",({ 
	  "I will kill all you foreign scum!",
	  "Take arms!  We are under attack!",
	  "To fast for you, huh!",
	  "Take that you scum!"
	}),1);
	new("/wizards/khojem/zone/weapon/halberd")->move(this_object());
	force_me("wield halberd in right hand and left hand");
}
