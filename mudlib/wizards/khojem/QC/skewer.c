//  Wizard:  Khojem 
//  Newbie Wizard Skewer

inherit "/std/weapon";

create() { 
  int   idx; 
  mixed ench_str; 
  ::create(); 
  set_name("skewer");
  set_ac(8); 
  set("id", ({ "spear", "skewer" })); 
  set("short", "Khojem's Great Newbie-Wizard Skewer"); 
  set("long", "This is used to impale wizards who gen "+
    "big weapons in their areas."); 
  set_type("two handed polearm"); 
  set_quality(6); 
  set_wc(28, "impaling");

  // set enchantment - *glow* in short description
  set_property("enchantment",4);

  // maximum spell stacking for flame blade is 4 
  // see /std/spells/flame_blade.c  
  set_property("flame blade", 4);

  // wc = (power+2) * stack  so, (6 +2) *2 = 32
  set_wc(32,"fire");

  // allows enchanter w/ detect magic skill to determine
  // magic and power of magic on LOOK AT SKEWER
  ench_str = ({ ({ "This weapon has %^ORANGE%^Flame Blade%^RESET%^.",
  "detect magic" }) });
  set_property("extra long",ench_str);

  set_verb("spear");
  set_parry_bonus(-10);
  set_weight(95);
  set_value(120); 
}
