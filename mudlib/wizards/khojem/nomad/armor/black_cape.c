//  Wizard:  Khojem
//  Black Cape
//  black_cape.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("black cape");
    set("id", ({ "cape", "black cape" }) );
    set("short", "A black cape");
    set("long", "The heavy cloth is darke.  It can be worn over "+
      "other armor and will protect you from the cold desert nights.");
    set_weight(95);
    set_value(700);
    set_type("cloak");
    set_limbs( ({ "torso" }) );
    set_ac(15);
        set_ac(1, "aether");
        set_ac(1, "depression");
        set_ac(5, "acid");
        set_ac(1, "vacuum");
        set_ac(5, "fire");
        set_ac(10, "cold");
        set_ac(2, "impact");
        set_ac(1, "stress");
        set_ac(2, "strike");
        set_ac(5, "impaling");
        set_ac(1, "electricity");
        set_ac(1, "time");
        set_ac(10, "crushing");
        set_ac(1, "disruption");
        set_ac(1, "holy");
        set_ac(1, "plasma");
        set_ac(1, "infernal");
        set_material("misc/wool");
}
