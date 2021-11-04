//  Wizard:  Khojem
//  viper's fangs
//  viper_fangs.c

inherit "/std/weapon";

create() {
    ::create();
    set_name("viper's fangs");
    set_ac(4);
    set("id", ({ "viper's fangs", "fangs", 
      "short sword", "sword", "shortsword" }));
    set("short", "viper's fangs");
    set("long", "The short sword is a mean-looking weapon with "+
      "slightly-serrated, triangular-shaped dual blades.  "+
      "It has a small cupped shield that protects the hand while wielded."
    );
    set_type("blade");
    set_quality(6);
    set_wc(15, "impaling");
    set_verb("stab");
    set_parry_bonus(10);
    set_weight(60);
    set_value(3500);
    set_hit( (: this_object(), "weapon_strike" :) );
    set_wield( (: this_object(), "wield_dagger" :) );
}

int wield_dagger(){
  if(((int)this_player()->query_skill("blade")) < 60) {
    write("Odd?!  You don't seem to know how to do that.\n");
    return 0;
  } else
  write("You slip your hand around the short sword's handle.\n");
  return 1;
}

mapping weapon_strike(object attacker) {
  if(((string)attacker->query_race()=="undead")) {
    write("The viper fang's hiss while you stab deeply into your opponent!");
    return(["impaling" : 22]);
  }
  else return 0;
}
