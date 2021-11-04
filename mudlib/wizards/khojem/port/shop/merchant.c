//  Wizard:   Khojem
//  Monster:  merchant man
//  File:     merchant.c

#include <std.h>

inherit MONSTER;
 
create() {
  object money;
  ::create();
    set_name("merchant");
    set_id( ({ "merchant man", "merchant" }) );
    set_level(9);
    set_short("merchant man");
    set_long("The merchant man is a resting here from a long voyage.  He spends "+
      "most of his time on the open sea, but while in port he likes to indulge "+
      "in a few drinks."
      );
    set("race", "half-elf");
    set_gender("male");
    set_body_type("human");
    set_overall_ac(5);
    set_property("melee damage", ([ "crushing" : 15]));
    set_languages(({"common", "stormspeak", "drow", "middle-english" }));
    set_lang_prof("common",10);
    set_lang_prof("stormspeak",10);
    set_lang_prof("drow",8);
    set_lang_prof("middle-english",8);
    set_primary_lang("common");
   set_emotes(2, ({
	 "The merchant man's head nods.",
	 "The merchant man's head nods.",
	 "The merchant man's head nods.",
	 "The merchant man takes a sip of his drink.",
	}),0);
}
