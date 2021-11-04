//  Khojem
//  flail
//  flail.c

inherit "/std/weapon";

create() {
  int   idx; 
  mixed ench_str; 
    ::create();
    set_name("ball and chain");
    set_ac(5);
    set("id", ({ "ball", "ball and chain", "chain", "flail" }));
    set("short", "ball and chain");
    set("long", "This weapon has a short metal rod with leather wrappings at one "+
      "end for a sure grip.  Attached to the other end of the rod is a short chain "+
      "with a spiked metal ball connected to the chain's end."
    );
    set_type("flail");
    set_quality(6);
    set_wc(19, "crushing");
  	set_wc(4, "fire");
    set_verb("smash");
    set_parry_bonus(-15);
    set_weight(120);
    set_value(120);
    set_hit_bonus(-2);
    set_wield( (: call_other, this_object(), "wield_blade" :) );
    set_hit( (: call_other, this_object(), "weapon_strike" :) );
    set_property("enchantment",1);
    set_property("flame blade", 1);
    ench_str = ({ ({ "This weapon has %^ORANGE%^Flame Blade%^RESET%^.",
    "detect magic" }) });
    set_property("extra long",ench_str);
}

mapping weapon_strike(object attacker) {
  if(((string)attacker->query_race()=="undead")){
    write("The spiked ball glows red as you pummel your opponent!");
    return(["crushing" : 10]);
  }
  else return 0;
}

int wield_blade(){
  if((int)this_player()->query_skill("flail") < 50) {
    write("Odd?!  You don't seem to know how to do that.\n");
    return 0;
  }
  write("As you grip the flail a slight warm tingling shoots up your arm.");
  return 1;
}
