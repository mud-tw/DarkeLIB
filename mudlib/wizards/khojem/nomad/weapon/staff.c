//  Wizard:  Khojem
//  Staff of Rom'mir
//  nomad_staff.c

inherit "/std/weapon";

void init() {
    add_action("read_runes","read");
    add_action("do_help","help");
	::init();
}

create() {
    ::create();
    set_ac(10);
    set_name("staff of rom'mir");
    set("id", ({ "staff of rom'mir", "staff", "rom'mir", "rommir" }));
    set("short", "Staff of Rom'mir");
    set("long", "A long, iron staff over six feet in length and gently "+
      "curved at one end.  Its entire length is covered with cryptic nomadic "+
      "runes."
    );
    set_type("two handed staff");
    set_quality(6);
    set_wc(20, "crushing");
    set_verb("bludgeon");
    set_parry_bonus(30);
    set_weight(50);
    set_value(100);
    set_property("enchantment", 4);
    set_wield( (: call_other, this_object(), "wield_staff" :) );
    set_unwield( (: call_other, this_object(), "unwield_staff" :) );
    set_hit( (: call_other, this_object(), "weapon_strike" :) );
}


int read_runes(string str) {
  if(str == "runes" || str == "staff") {
    say(this_player()->query_cap_name()+" studies the runes on the staff.\n");
    if(((int)this_player()->query_stats("intelligence")) > 80) {
      write("You are suddenly overjoyed for all the long hours you spent "+
        "learning the history of the ancient battles.  You are unable "+
        "to deciper the runes, but you identify them as dating back 500 years "+
        "to the first great battle between the Army of Shadow and the Allied "+
        "Army of the Free Races.  That terrible, bloody battle where the evil "+
        "lieutenant of Marghuul, Ther'Kal, was slain in the desert near "+
        "Bir'Barrutt.\n\n"+
        "You ponder those history lessons from your youth and recall the "+
        "legendary desert mages who fought alongside Lord Commander Ganelon, "+
        "leader of the Allied Army of the Free Races.  Legendary tales said "+
        "those mysterious mages focused their magic on the weapons wielded by the "+
        "Allied Army, bestowing those arms with great magic.\n");
      return 1;
    }
    return 0;
  }
}


int wield_staff(){
  if(((int)this_player()->query_skill("two handed staff")) < 55) {
    write("Odd?!  You don't seem to know how to do that.");
    return 0;
  }      
  write("A warm pulse shoots up your arms.");
      return 1;
}

int unwield_staff(){
    write("A brief chill runs up your forearms.");
    return 1;
}

mapping weapon_strike(object attacker) {
  int zquality;
  zquality = (this_object()->query_quality());
  if(zquality > 4) {
  	set_wc(4, "fire");
    write("The staff's tip ignites in a bright flash as it hits your opponent!");
  }
  else {
    if(zquality > 1){
      set_wc(1, "fire");
      write("The staff's tip briefly ignites in a blue flash as it "+
        "strikes your opponent!");
    }
    else set_wc(0, "fire");
  }
  if(((string)attacker->query_race()=="undead")) return(["crushing" : 28]);
}

int do_help(string str) {
  if(!id(str)) { return 0; }
  if(((int)this_player()->query_skill("detect magic")) > 40) {
    write("You sense that the Staff of Rom'mir is capable of "+ 
      "subjecting its victims to damage by fire and crushing attacks.\n");
    return 1;
    }
  write("You are unable to sense the magic contained within this staff.\n");
  return 1;
}

