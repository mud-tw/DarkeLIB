//   Khojem
//   Captain, Palace Guard
//   captain.c


#include <std.h>

inherit MONSTER;

create() {
	::create();
	set_name("Captain");
	set("id", ({ "guard", "palace", "captain" }) );
	set_level(15);
	set("short", "Captain of the Guard");
	set("long",
		"The Captain of the Palace Guard is a well-equipped veteran."
	);
	add_money("gold", random(500));
	set_alignment(0);
	set("race", "sword-demon");
	set_gender("male");
	set_class("fighter");
	set_body_type("human");
	set_overall_ac(20);
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	set_skill("melee", 30);
	set_skill("dodge",30);
	set_skill("parry",30);
	set_skill("attack", 30);
	set_skill("blade", 40);
	set_skill("dual_attack",20);
	set_skill("offhand_training",10);
	set_skill("stalk",20);
	set_skill("stealth",30);
	set_wimpy(0);
	set_moving(1);
	set_speed(120);
	set("aggressive", 1);
	set_languages("Yin");
	set_emotes(5, ({
	  "The captain snickers wickedly.",
	  "The captain gnashes his teeth.",
	  "The captain wipes sweat from his brow with his forearm.",
	  "The captain spits his chewing tobacco into your eyes."
	}),1);
	set_speech(10,"Yin",({ 
	  "I learned much in the Wasteland Wars.",
	  "Time to die, puke!",
	  "Sound the alarm!  We are under attack!",
	  "That was a good move.  I will remember that one!",
	  "I fought many a foe better than you!"
	}),1);
	new("/wizards/khojem/zone/weapon/long_sword")->move(this_object());
	force_me("wield longsword in right hand");
	new("/wizards/khojem/zone/weapon/rapier")->move(this_object());
	force_me("wield rapier in left hand");
	new("/wizards/khojem/zone/armor/chain_coif")->move(this_object());
	force_me("wear coif");
	new("/wizards/khojem/zone/armor/scale_mail")->move(this_object());
	force_me("wear mail");
}
