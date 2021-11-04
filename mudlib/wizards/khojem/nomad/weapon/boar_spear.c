//  Khojem
//  boar's spear
//  boar_spear.c

inherit "/std/weapon";

create() {
    ::create();
    set_name("boar spear");
    set_ac(4);
    set("id", ({ "spear", "boar's spear", "boar spear", "boar", "polearm" }));
    set("short", "boar's spear");
    set("long", "The spear is half again longer than a man is tall.  It is constructed "+
      "of metal and wrapped with leather straps along its shaft to provide a sure grip.  "+
      "One end tapers to a triangular tip with deep grooves to allow blood to flow "+
      "out of the victim after spearing.  A few feet up the shaft from the tip are two "+
      "angular barbs that curve and point towards the tip.  These barbs are used to "+
      "hold off a victim after impaling.  A wild boar could further impale itself by "+
      "running up the shaft towards its wielder.  The barbs would hold the boar at bay."
    );
    set_type("two handed polearm");
    set_quality(6);
    set_wc(20, "impaling");
    set_verb("spear");
    set_parry_bonus(-10);
    set_weight(120);
    set_value(30);
    set_hit( (: call_other, this_object(), "weapon_strike" :) );
}

mapping weapon_strike(object attacker) {
  if(((string)attacker->query_race()=="undead")){
    write("The boar's spear pulses a dull blue as you impale your opponent!");
    return(["impaling" : 10]);
  }
  else return 0;
}
