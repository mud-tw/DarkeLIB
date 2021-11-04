//   Khojem
//   Palace Guard 2
//   plguard2.c


#include <std.h>

inherit MONSTER;

create() {
	::create();
	set_name("Palace Guard");
	set("id", ({ "guard", "palace" }) );
	set_level(6);
	set("short", "Palace Guard");
	set("long",
		"A well armored and equiped Palace Guard is here defending the city."
	);
	add_money("gold", random(100));
	set_alignment(0);
	set("race", "sword-demon");
	set_gender("male");
	set_body_type("human");
	set_overall_ac(20);
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	set_skill("melee", 20);
	set_skill("attack", 40);
	set_skill("two handed polearm", 40);
	set_wimpy(0);
	set("aggressive", 1);
	set_languages("Yin", 5);
	set_emotes(30, ({"The Palace Guard looks determined to kill you."}),1);
	set_speech(10, "Yin", ({ "To my aid, brothers!  We are under attack!" }),1);
	new("/wizards/khojem/zone/weapon/polearm")->move(this_object());
	force_me("wield polearm in right hand and left hand");
	new("/wizards/khojem/zone/armor/stud_jacket")->move(this_object());
	force_me("wear jacket");
}
