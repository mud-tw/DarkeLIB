//  Wizard:  Khojem
//  Barfir
//  barfir.c

#include <std.h>

inherit BARKEEP;

create() {
    ::create();
   set_property("no bump", 1);
   set_name("barfir");
   set_id( ({ "barfir", "barkeep" }) );
   set_short("Barfir, the long-time, proprietor of Barfir's Pub & Alehouse");
   set_level(12);
   set_long("Barfir is an aging, wood-elf who dutifully tends his bar.");
   set_gender("male");
   set_alignment(122);
   set("race", "wood-elf");
   add_money("silver", random(500));
   set_body_type("human");
   set_currency("silver");
   set_menu(
	({ "firebreather", "special", "ale" }),
	({ "alcoholic", "alcoholic", "alcoholic" }),
	({ 25, 15, 3 })
   );
   
   set_my_mess(
	 ({
	 "The firebreather burns your throat!\n",
	 "Wow! Barfir's specialty is potent!\n",
	 "You down some elven mead ale.\n"
	 })
   );
   
    set_your_mess(
	  ({
	  "screams from the burning of a drink of a firebreather.\n",
	  "drinks a special of the house.\n",
	  "drinks some elven mead ale.\n"
      })
    );
    
    set_menu_short(
	  ({
	  "A firebreather",
	  "A special of the house",
	  "An elven mead ale"
	  })
    );
    
    set_menu_long(
	  ({
	  "A firebreather from Barfir's Pub & Alehouse.\n",
	  "A classic special of the house from Barfir's Pub & Alehouse.\n",
	  "A dark, elven mead ale brewed by Barfir himself.\n"
   	  })
    );
}
