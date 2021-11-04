//  Khojem
//  darkeblade
//  darkeblade.c

inherit "/std/weapon";

create() {
    ::create();
    set_name("darkeblade");
    set_ac(5);
    set("id", ({ "blade", "darkeblade" }));
    set("short", "darkeblade");
    set("long", "This mean-looking blade is made from darkemetal.  "+
      "The blade looks sharp and does not reflect any light.  "
    );
    set_type("blade");
    set_quality(6);
    set_wc(18, "cutting");
    set_wc(8, "impaling");
    set_verb("slice");
    set_parry_bonus(8);
    set_weight(100);
    set_value(300);
    set_wield( (: call_other, this_object(), "wield_blade" :) );
    set_hit( (: call_other, this_object(), "weapon_strike" :) );
}

mapping weapon_strike(object attacker) {
  if(((string)attacker->query_race()=="undead")){
    write("The darkeblade whistles brilliantly as it impales your
opponent!");
    return(["impaling" : 16]);
  }
  else return 0;
}

int wield_blade(){
  if((int)this_player()->query_skill("blade") < 70) {
    write("Odd?!  You don't seem to know how to do that.\n");
    return 0;
  }
  else return 1;
}
