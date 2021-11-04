//  Khojem
//  Rapier
//  rapier.c

inherit "/std/weapon";

create() {
    ::create();
    set_name("rapier");
    set_ac(3);
    set("id", ({ "rapier" }));
    set("short", "rapier");
    set("long", "This short, two-edged sword with a narrow pointed blade "+
      "is prized by all well-skilled swordsman and fighters."
    );
    set_type("blade");
    set_quality(6);
    set_wc(7, "cutting");
    set_wc(4, "impaling");
    set_verb("slice");
    set_parry_bonus(8);
    set_weight(30);
    set_value(250);
    set_wield( (: call_other, this_object(), "wield_rapier" :) );
    set_hit( (: call_other, this_object(), "weapon_strike" :) );
    return;
}

mapping weapon_strike(object attacker) {
  if(((string)attacker->query_race()=="undead")) {
    write("The rapier humms loudly as it impales your opponent!");
    return(["impaling" : 8]);
  }
  else return 0;
}

int wield_rapier(){
  if((int)this_player()->query_skill("offhand training") < 35) {
    write("Odd?!  You don't seem to know how to do that.\n");
    return 0;
  }
  else return 1;
}
