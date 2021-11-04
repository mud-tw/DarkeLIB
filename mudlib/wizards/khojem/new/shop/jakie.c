//  Wizard:  Khojem
//  Shakey Jakie
//  jakie.c

#include <std.h>

inherit BARKEEP;

create() {
    ::create();
   set_property("no bump", 1);
   set_name("jakie");
   set_id( ({ "jakie", "barkeep", "shakie jakie" }) );
   set_short("Shakey Jakie");
   set_level(2);
   set_long("Shakey Jakie is a fat, old wood-elf with a beer gut.");
   set_gender("male");
   set_alignment(-10);
   set("race", "wood-elf");
   add_money("gold", random(100));
   set_body_type("human");
   set_currency("silver");
   set_menu(
	({ "moonshine", "ale", "bread" }),
	({ "alcoholic", "alcoholic", "food" }),
	({ 20, 4, 5 })
   );
   
   set_my_mess(
	 ({
	 "The moonshine burns a layer of skin off your throat!\n",
	 "You open your throat and chug some pale elven ale.\n",
	 "The bread is crusty and stale.\n"
	 })
   );
   
    set_your_mess(
	  ({
	  "drinks the moonshine and suddenly his eyes bulge.\n",
	  "chugs some pale elven ale.\n",
	  "eats a piece of bread.\n"
      })
    );
    
    set_menu_short(
	  ({
	  "A bottle of moonshine",
	  "A draft of pale elven ale",
	  "A crusty piece of brown bread"
	  })
    );
    
    set_menu_long(
	  ({
	  "A clear, unlabeled bottle of Shakey's moonshine.\n",
	  "A dark bottle of Shakey's pale elven ale.\n",
	  "A stale, brown piece of bread.\n"
   	  })
    );
}

