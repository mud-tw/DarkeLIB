//  Khojem
//  Scepter of Moped
//  scepter2.c

inherit "/std/weapon";

void init() {
    add_action("read_runes","read");
    add_action("do_help","help");
	::init();
}

create() {
    ::create();
    set_name("scepter");
    set_ac(10);
    set("id", ({ "scepter", "scepter of moped" }));
    set("short", "Scepter of Moped");
    set("long", "The sceptre is finely crafted from a solid piece of white metal.  "+
      "Numerous jewels are crafted to the surface of the scepter.  "+
      "The sceptre is sculptured with many runes."
    );
    set_type("blunt");
    set_quality(6);
    set_wc(16, "crushing");
    set_verb("pummel");
    set_parry_bonus(10);
    set_weight(40);
    set_wc(4, "fire");
    set_property("enchantment", 4);
    set_value(2000);
    set_wield( (: this_object(), "wield_scepter" :) );
    set_hit( (: this_object(), "weapon_strike" :) );
    return;
}

mapping weapon_strike(object attacker) {
  if((string)attacker->query_race()=="undead") {
    write("The scepter throbs as it pounds your opponent's body!");
    return(["crushing" : 12]);
  }
  else return 0;
}

int wield_scepter(){
  if((int)this_player()->query_skill("blunt") < 70) {
    write("Odd?!  You don't seem to know how to do that.\n");
    return 0;
  }
  else return 1;
}

int do_help(string str) {
  if(!id(str)) { return 0; }
  if(((int)this_player()->query_skill("detect magic")) > 60) {
    write("Your knowledge of ancient runes identify this scepter as "+
      "enchanted with special fire damage capabilities.\n");
    return 1;
    }
  write("You are unable to sense the magic contained within the scepter.\n");
  return 1;
}

int read_runes(string str) {
  if(str == "runes" || id(str)) {
    say(this_player()->query_cap_name()+" studies the scepters runes.\n");
    if(((int)this_player()->query_stats("intelligence")) > 80) {
      write("Your knowledge of ancient runes identify this scepter as "+
        "an ancient weapon dating back over 500 years to the first great "+
        "battle between the Army of Shadow and the Allied "+
        "Army of the Free Races.  That terrible, bloody battle where the evil "+
        "lieutenant of Marghuul, Ther'Kal, was slain in the desert near "+
        "Bir'Barrutt.\n\n"+
        "You read that desert mages "+
        "fought alongside Lord Commander Ganelon, "+
        "leader of the Allied Army of the Free Races.  The mages enchanted "+
        "many of the weapons wielded by the "+
        "Allied Army, bestowing those arms with great magic.\n");
      return 1;
    }
    return 0;
  }
}


