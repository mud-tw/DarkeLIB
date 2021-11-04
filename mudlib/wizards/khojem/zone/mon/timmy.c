//  Khojem
//  Monster:  Timmy

#include <std.h>

inherit MONSTER;

create() {
  ::create();
    set_name("Timmy");
    set_id( ({ "tim", "timmy" }) );
    set_level(1);
    
    set_short("Timmy a hapless fool is here");
    set_long("Timmy is a bearded, hunched man with a waterbottle attached "+
      "to a web-belt strapped around his waist.  He has his finger up his "+
      "nose."
      );
    set("race", "human");
    set_gender("male");
    set_body_type("human");
    set_stats("intelligence", 10);
    set_property("melee damage", ([ "crushing" : 0]));
    set_skill("melee", 10);
    set_skill("dodge", 5);
    set_skill("parry", 5);
    set_stats("dexterity", 10);
    set_max_hp(20);
    set_hp(20);
    set_speed(1000);
    set_moving(1);
}

