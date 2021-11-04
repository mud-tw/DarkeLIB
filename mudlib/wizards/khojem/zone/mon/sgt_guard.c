//   Khojem
//   Sergeant
//   captain.c


#include <std.h>

inherit MONSTER;

create() {
	::create();
	set_name("Sergeant of the Guard");
	set("id", ({ "guard", "sergeant", "sergeant of the guard" }) );
	set_level(10);
	set("short", "Sergeant of the Guard");
	set("long",
		"The Sergeant of the Guard looks like a brute.  He is "+
		"well-equipped and doesn't like the sight of you."
	);
	add_money("gold", random(300));
	set_alignment(0);
	set("race", "sword-demon");
	set_gender("male");
	set_class("fighter");
	set_body_type("human");
	set_overall_ac(12);
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	set_skill("melee", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_skill("attack", 20);
	set_skill("two handed blade", 30);
	set_wimpy(0);
	set("aggressive", 1);
	set_languages("Yin");
	set_emotes(5, ({
	  "The sarge snickers wickedly.",
	  "The sarge gnashes his teeth.",
	  "The sarge wipes sweat from his brow.",
	  "The sarge steps on your foot."
	}),1);
	set_speech(10,"Yin",({ 
	  "I learned to fight well during the Wasteland Wars.",
	  "Time for you to learn a few lessons!",
	  "Sound the alarm!  We are under attack!",
	  "Is that the best you can do?",
	  "I fought many better than you!"
	}),1);
	new("/wizards/khojem/zone/weapon/bastard_sword")->move(this_object());
	force_me("wield bastard sword in right hand");
}
