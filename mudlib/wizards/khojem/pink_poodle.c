//  Khojem
//  Monster:  Pink Poodle

#include <std.h>

inherit MONSTER;

create() {
  ::create();
    set_name("poodle");
    set_id( ({ "poodle", "dog" }) );
    set_level(1);
    set_short("a pink poodle");
    set_long("This is a small poodle, painted pink by some insane owner.  "+
     "It looks to have seen harder times recently, and shivers constantly, "+
     "due to the lack of fur on it's midsection.  Other than that, it looks "+
     "just like every other pink poodle you've seen.\n"+
     "The poodle looks a little dizzy."
      );
    set("race", "dog");
    set_gender("male");
    set_body_type("quadraped");
    set_stats("intelligence", 10);
    set_property("melee damage", ([ "crushing" : 0]));
    set_skill("melee", 10);
    set_skill("dodge", 5);
    set_skill("parry", 5);
    set_stats("dexterity", 10);
    set_max_hp(20);
    set_hp(20);
    set_emotes(35,({
      "The poodle attempts to wag it's tail, but only manages to twitch slightly.",
      "The poodle shivers uncontrollably.",
    }),0);    
}

