//  Wizard:  Khojem
//  blue sash
//  blue_sash.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("blue sash");
    set("id", ({ "sash", "blue sash" }) );
    set("short", "a blue sash");
    set("long", "A wide, blue sash made of silk and worn around the waist.");
    set_weight(75);
    set_value(400);
    set_type("belt");
    set_ac(9);
    set_limbs( ({ "torso" }) );
        set_ac(2, "aether");
        set_ac(2, "depression");
        set_ac(5, "acid");
        set_ac(2, "vacuum");
        set_ac(9, "fire");
        set_ac(9, "cold");
        set_ac(2, "impact");
        set_ac(2, "stress");
        set_ac(2, "strike");
        set_ac(9, "cutting");
        set_ac(9, "impaling");
        set_ac(2, "electricity");
        set_ac(2, "time");
        set_ac(9, "crushing");
        set_ac(2, "disruption");
        set_ac(2, "holy");
        set_ac(2, "plasma");
        set_ac(2, "infernal");
        set_material("misc/silk");
}
