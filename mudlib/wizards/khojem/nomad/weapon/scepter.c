//  Khojem
//  Scepter of Bir'Barrutt
//  scepter.c

inherit "/std/weapon";

create() {
    ::create();
    set_name("scepter");
    set_ac(3);
    set("id", ({ "scepter" }));
    set("short", "a scepter");
    set("long", "The sceptre is finely crafted from a solid piece of
darkemetal.  "+
      "It is a dull black metal that reflects no light.  "+
      "The sceptre is sculptured with many runes, but you can read that
this "+
      "sceptre is the Scepter of Bir'Barrutt."
    );
    set_type("blunt");
    set_quality(6);
    set_wc(14, "crushing");
    set_verb("pound");
    set_parry_bonus(8);
    set_weight(110);
    set_value(200);
    set_wield( (: call_other, this_object(), "wield_scepter" :) );
    set_hit( (: call_other, this_object(), "weapon_strike" :) );
    return;
}

mapping weapon_strike(object attacker) {
  if((string)attacker->query_race()=="undead") {
    write("The scepter throbs as it pounds your opponent's body!");
    return(["crushing" : 16]);
  }
  else return 0;
}

int wield_scepter(){
  if((int)this_player()->query_skill("blunt") < 50) {
    write("Odd?!  You don't seem to know how to do that.\n");
    return 0;
  }
  else return 1;
}
