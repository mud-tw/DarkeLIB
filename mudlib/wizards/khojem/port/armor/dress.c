//  Wizard:  Khojem
//  woman's dress
//  dress.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("leather dress");
    set("id", ({ "dress", "leather dress" }) );
    set("short", "leather dress");
    set("long", "The leather dress is worn.  It is covered with spilled beer "+
      "stains and has a few cigar burns.  It hangs low across the bosom.");
    set_weight(10);
    set_value(1);
    set_type("armour");
    set_limbs( ({ "torso" }) );
    set_material("misc/leather");
    set_ac(1);
}

