//  Wizard:  Khojem
//  Sparkey - barkeep of the Sailor's Pleasure
//  sparkey.c

#include <std.h>

inherit BARKEEP;

create() {
    ::create();
   set_property("no bump", 1);
   set_name("sparkey");
   set_id( ({ "sparkey", "barkeep" }) );
   set_short("Sparkey, the barkeep");
   set_level(12);
   set("aggressive", 0);
   set_long("Sparkey is an old sailor with a fine love for the sea.  He wears "+
     "an eyepatch over the right eye.");
   set_gender("male");
   set_exp(4000);
   set("race", "high-man");
   set_overall_ac(20);
   set_hp(3500);
   set_property("melee damage", ([ "crushing" : 30]));
   set_skill("melee",220);
   set_skill("elementalism", 175);
   set_spell_level("elemental storm", 6);
   add_spell("elemental storm", "");
   set_combat_chance(80);
   add_money("mithril", random(100));
   set_body_type("human");
   set_languages(({"common"}));
   set_lang_prof("common",10);
   set_primary_lang("common");
   set_speech(1,"common",({ 
	  "I had a big fish!  Just like that one!",
	  "If you want that kinda service go to Beltar's place...  Rrrrr!",
	  "I hope you have word of the pirates just off shore!",
	  "This is a fine port-o-call.  May your stay here be good!"
	}),0);
   set_currency("silver");
   set_menu(
	({ "whiskey", "port", "beer", "lamb", "salmon", "roll", }),
	({ "drink_in", "drink_in", "alcoholic", "dine_in", "dine_in", "food", }),
	({ 15, 10, 2, 15, 10, 2, })
   );
   
   set_my_mess(
	 ({
	 "The shot of whiskey goes down smooth.\n",
	 "You sip down the fine port.\n",
	 "The cold beer quenches your thirst.\n",
	 "The rack of lamb was well prepared.\n",
	 "The filet of salmon had a well prepared dill sauce.\n",
	 "The dinner roll was soft and moist.\n"
	 })
   );
   
    set_your_mess(
	  ({
	  "throws down a shot of fine whiskey.\n",
	  "savors the fine glass of port wine.\n",
	  "takes a few quick swigs from a bottle of beer.\n",
	  "savors every morsel of a fine rack of lamb.\n",
	  "dines on a filet of salmon with dill sauce.\n",
	  "eats a dinner roll dripping with melted butter.\n"
      })
    );
    
    set_menu_short(
	  ({
	  "A shot of whiskey",
	  "A glass of fine port wine",
	  "A bottle of beer",
	  "A rack of lamb",
	  "A salmon filet",
	  "A dinner roll"
	  })
    );
    
    set_menu_long(
	  ({
	  "A shot of blended whiskey.\n",
	  "A small snifter of port wine.\n",
	  "A bottle of beer.\n",
	  "A finely prepared rack of lamb.\n",
	  "A filet of salmon with dill sauce.\n",
	  "A moist dinner roll\n"
   	  })
    );
}

int query_num_rounds() { return 3; }

string query_element() { return "vacid"; }

