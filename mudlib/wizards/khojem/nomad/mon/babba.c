//  Wizard:  Khojem
//  Babba
//  babba.c

#include <std.h>

inherit BARKEEP;

create() {
    ::create();
   set_property("no bump", 1);
   set_name("babba");
   set_id( ({ "babba", "barkeep" }) );
   set_short("Babba, the proprietor of Babba's Pub & Hashish House");
   set_level(19);
   set_long("Babba is a huge nomad.  His gut is of massive portions!  "+
     "Babba's head is completely shaved and he sports "+
     "a thick, dark mustache.");
   set_gender("male");
   set_exp(20000);
   set("race", "high-man");
   add_money("silver", random(500));
   set_body_type("human");
   set_currency("silver");
   set_menu(
	({ "firebreather", "special", "ale" }),
	({ "alcoholic", "alcoholic", "alcoholic" }),
	({ 30, 15, 5 })
   );
   
   set_my_mess(
	 ({
	 "The firebreather burns your throat!\n",
	 "Babba's special goes down like syrup.  You immediately feel its effects.\n",
	 "You quaff down the dark, nomadic ale.  It has a strong, bitter taste. \n"
	 })
   );
   
    set_your_mess(
	  ({
	  "screams from the burning of a drink of a firebreather.\n",
	  "drinks an opium special of the house.\n",
	  "drinks some nomadic ale.\n"
      })
    );
    
    set_menu_short(
	  ({
	  "A firebreather",
	  "A opium special of the house",
	  "An dark, nomad ale"
	  })
    );
    
    set_menu_long(
	  ({
	  "A firebreather from Babba's Pub and Hashish House.\n",
	  "An opium special of the house from Babba's Pub and Hashish House.\n",
	  "A dark, heady nomad ale brewed at Babba's Pub and Hashish House.\n"
   	  })
    );
}
