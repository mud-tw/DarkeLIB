//  Wizard:  Khojem
//  white sash
//  white_sash.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("white sash");
    set("id", ({ "sash", "white sash" }) );
    set("short", "a white sash");
    set("long", "A wide, white sash made of silk and worn around the waist.");
    set_weight(85);
    set_value(700);
    set_type("belt");
    set_ac(11);
        set_ac(2, "aether");
        set_ac(2, "depression");
        set_ac(3, "acid");
        set_ac(2, "vacuum");
        set_ac(11, "fire");
        set_ac(11, "cold");
        set_ac(3, "impact");
        set_ac(3, "stress");
        set_ac(3, "strike");
        set_ac(11, "cutting");
        set_ac(11, "impaling");
        set_ac(2, "electricity");
        set_ac(2, "time");
        set_ac(11, "crushing");
        set_ac(3, "disruption");
        set_ac(3, "holy");
        set_ac(3, "plasma");
        set_ac(2, "infernal");
        set_material("misc/silk");
    set_limbs( ({ "torso" }) );
}
