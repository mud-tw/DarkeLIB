//   Khojem
//   Palace Guard 1
//   plguard1.c


#include <std.h>

inherit MONSTER;

create() {
	::create();
	set_name("Palace Guard");
	set("id", ({ "guard", "palace" }) );
	set_level(4);
	set("short", "Palace Guard");
	set("long",
		"A well armored and equipped Palace Guard is here defending the city."
	);
	add_money("gold", random(100));
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
	set_emotes(5, ({"This Palace Guard wants to chop your head off."}),1);
	set_speech(10,"Yin",({ 
	  "I will kill all you foreign scum!",
	  "We are under attack!",
	  "That was a good move.  I will remember that one!",
	  "You are such a wimp!",
	  "My mother can fight better than you!"
	}),1);
	new("/wizards/khojem/zone/weapon/halberd")->move(this_object());
	force_me("wield halberd in right hand and left hand");
	new("/wizards/khojem/zone/armor/stud_pants")->move(this_object());
	force_me("wear pants");
}

