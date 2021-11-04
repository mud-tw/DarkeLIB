//  Khojem
//  triple-bladed sword
//  triple_blade.c

inherit "/std/weapon";

create() {
    ::create();
    set_name("triple-bladed sword");
    set_ac(4);
    set("id", ({ "sword", "triple-bladed sword", "blade" }));
    set("short", "triple-bladed sword");
    set("long", "This mean-looking sword is made from darkemetal.  Attached
to "+
      "the sword's handle, three long, darke blades extend parallel to each
other.  "+
      "The blades look sharp and do not reflect any light.  This is a
prized two "+
      "handed blade."
    );
    set_type("two handed blade");
    set_quality(6);
    set_wc(28, "cutting");
    set_wc(12, "impaling");
    set_verb("slice");
    set_parry_bonus(-10);
    set_weight(800);
    set_value(800);
    set_hit_bonus(-10);
    set_wield( (: call_other, this_object(), "wield_blade" :) );
    set_hit( (: call_other, this_object(), "weapon_strike" :) );
}

mapping weapon_strike(object attacker) {
  if(((string)attacker->query_race()=="undead")){
    write("The triple-bladed sword whistles brilliantly as it impales "+
     "your opponent!");
    return(["impaling" : 24]);
  }
  else return 0;
}

int wield_blade(){
  if((int)this_player()->query_skill("two handed blade") < 70) {
    write("Odd?!  You don't seem to know how to do that.\n");
    return 0;
  }
  else return 1;
}
