//  Wizard:  Khojem
//  Legionnaire's helmet
//  legion_helm.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("legionnaire's helmet");
    set("id", ({ "helmet", "legionnaire's helmet", "helm" }) );
    set("short", "plumed legionnaire's helmet");
    set("long", "The helmet looks like it will protect your head, but "+
      "this crop of 2-3 foot long feathers will make you look absurb!");
    set_weight(35);
    set_value(65);
    set_type("helmet");
    set_limbs( ({ "head" }) );
    set_ac(18);
        set_ac(1, "aether");
        set_ac(1, "depression");
        set_ac(5, "acid");
        set_ac(1, "vacuum");
        set_ac(10, "fire");
        set_ac(10, "cold");
        set_ac(5, "impact");
        set_ac(1, "stress");
        set_ac(10, "strike");
        set_ac(15, "cutting");
        set_ac(5, "impaling");
        set_ac(1, "electricity");
        set_ac(1, "time");
        set_ac(10, "crushing");
        set_ac(1, "disruption");
        set_ac(1, "holy");
        set_ac(1, "plasma");
        set_ac(1, "infernal");
        set_material("metal/iron");
}

