//  Wizard:  Khojem
//  green sash
//  green_sash.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("green sash");
    set("id", ({ "sash", "green sash" }) );
    set("short", "green sash");
    set("long", "A wide, green sash made of silk and worn "+
      "around the waist.");
    set_weight(50);
    set_value(200);
    set_type("belt");
    set_limbs(({ "torso" } ));
    set_ac(7);
        set_ac(2, "aether");
        set_ac(2, "depression");
        set_ac(5, "acid");
        set_ac(2, "vacuum");
        set_ac(7, "fire");
        set_ac(7, "cold");
        set_ac(2, "impact");
        set_ac(2, "stress");
        set_ac(2, "strike");
        set_ac(7, "cutting");
        set_ac(7, "impaling");
        set_ac(2, "electricity");
        set_ac(2, "time");
        set_ac(7, "crushing");
        set_ac(2, "disruption");
        set_ac(2, "holy");
        set_ac(2, "plasma");
        set_ac(2, "infernal");
        set_material("misc/silk");
}
