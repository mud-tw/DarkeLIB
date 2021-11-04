//  Wizard:  Khojem
//  Beltar - barkeep of the Rusty Parrote
//  beltar.c

#include <std.h>

inherit BARKEEP;

create() {
    ::create();
   set_property("no bump", 1);
   set_name("beltar");
   set_id( ({ "beltar", "barkeep" }) );
   set_short("beltar, the barkeep");
   set_level(12);
   set_long("Beltar is a bearded ol' sailor with one leg.  Much of the time he seems "+
     "distracted from tending bar while he tells sailing stories from his youth.");
   set_gender("male");
   set_overall_ac(20);
   set_hp(3500);
   set("aggressive", 0);
   set_exp(4000);
   set_property("melee damage", ([ "crushing" : 30]));
   set_skill("melee",220);
   set_skill("elementalism", 175);
   set_spell_level("elemental storm", 6);
   add_spell("elemental storm", "");
   set_combat_chance(80);
   add_money("gold", random(100));
   set("race", "ogre");
   add_money("silver", random(100));
   set_body_type("human");
   remove_limb("left leg");
   set_languages(({"common"}));
   set_lang_prof("common",10);
   set_primary_lang("common");
   set_emotes(2, ({
	 "Beltar nods as he listens to another sea story.",
	 "Beltar takes a long draw on his pipe.",
	 "Beltar takes a long draw on his pipe.",
	 "Beltar takes a long draw on his pipe.",
	 "Beltar hobbles down the bar and does some bartender stuff under the bar.",
	 "Beltar casts an eye your way and looks annoyed.",
	 "Beltar cast an eye your way and looks annoyed."
	}),0);
    set_speech(2,"common",({ 
	  "Arrr... annn eyee gueesh yew wanna dwink eh!",
	  "Grrr... tat whaal twas ta migtie whall... wit thos darck eyees!",
	  "Eyee hade ta hug teech.  Twas ta nrastie sark wit ded eyees!",
	  "Eyee, tat twas ta fyn part wit mnie wig ested witmen!"
	}),0);
   set_currency("silver");
   set_menu(
	({ "grain", "rum", "ale", "beer", "stew", "jerkie" }),
	({ "drink_in", "drink_in", "drink_in", "alcoholic", "dine_in", "food" }),
	({ 40, 25, 10, 2, 8, 2 })
   );
   
   set_my_mess(
	 ({
	 "The grain alcohol screams down your thoat while taking a layer of skin with it!\n",
	 "The mollassses-like, sugarcane rum is bitter, but does the trick!\n",
	 "You quaff down the high tankard of ale and rub your forearm across your mouth.\n",
	 "You empty the small bottle of beer in a few swigs.\n",
	 "You gulp down the cold crab stew not knowing what Beltar may have put in the stew.\n",
	 "You eat the dry, tough beef jerkie.\n"
	 })
   );
   
    set_your_mess(
	  ({
	  "face turns red and eyes bulge after shooting down the grain alcohol.\n",
	  "quickly tosses down the rum.\n",
	  "quaffs down the tall tankard of ale and then brushes the foam off with "+
	    "his forearm.\n",
	  "takes a few, quick swigs from the beer bottle.\n",
	  "gulps down some thick crab stew.\n",
	  "eats some beef jerkie.\n"
      })
    );
    
    set_menu_short(
	  ({
	  "A shot of grain alcohol",
	  "A small glass of rum",
	  "A tall tankard of ale",
	  "A small bottle of beer",
	  "A small bowl of crab stew",
	  "A short stick of beef jerkie"
	  })
    );
    
    set_menu_long(
	  ({
	  "A small shot of grain alcohol in a small shotglass.\n",
	  "A short glass of rum in a dirty glass.\n",
	  "A tall, pewter tankard of ale.\n",
	  "A small, dark bottle of beer.\n",
	  "A small bowl of crab stew.\n",
	  "A stick of beef jerkie.\n"
   	  })
    );
}

int query_num_rounds() { return 3; }

string query_element() { return "vacid"; }

