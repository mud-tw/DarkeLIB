//  Wizard:  Khojem
//  obsidian dirk
//  ob_dirk.c

inherit "/std/weapon";

create() {
    ::create();
    set_name("obsidian dirk");
    set_ac(1);
    set("id", ({ "obsidian dirk", "dirk" }));
    set("short", "obsidian dirk");
    set("long", "The dirk is made of a solid piece of obsidian.  The blade
is "+
      "chipped to a black, glassy razor sharp edge."
    );
    set_type("knife");
    set_quality(6);
    set_wc(14, "impaling");
    set_verb("stab");
    set_parry_bonus(-10);
   set_value(120);
    set_weight(50);
    set("throwable",1);
    set_wield( (: call_other, this_object(), "wield_dirk" :) );
    set_hit( (: call_other, this_object(), "weapon_strike" :) );
}


mapping weapon_strike(object attacker) {
  if(((string)attacker->query_race()=="undead")) {
    write("The dirk hisses as it stabs deeply into your opponent!");
    return(["impaling" : 20]);
  }
  else return 0;
}

int wield_dirk(){
  if(((int)this_player()->query_skill("knife")) < 70) {
    write("Odd?!  You don't seem to know how to do that.\n");
    return 0;
  }
  else return 1;
}
