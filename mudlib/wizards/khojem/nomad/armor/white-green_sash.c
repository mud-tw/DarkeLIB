//  Wizard:  Khojem
//  white-green sash
//  white-green_sash.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("white-green sash");
    set("id", ({ "sash", "white-green sash" }) );
    set("short", "a white-green sash");
    set("long", "A wide, sash made of silk and worn around the waist.  "+
      "It has alternating white and green stripes across it.");
    set_weight(20);
    set_value(1000);
    set_type("belt");
    set_ac(15);
        set_ac(2, "aether");
        set_ac(2, "depression");
        set_ac(5, "acid");
        set_ac(2, "vacuum");
        set_ac(15, "fire");
        set_ac(15, "cold");
        set_ac(5, "impact");
        set_ac(5, "stress");
        set_ac(5, "strike");
        set_ac(15, "cutting");
        set_ac(15, "impaling");
        set_ac(2, "electricity");
        set_ac(2, "time");
        set_ac(15, "crushing");
        set_ac(5, "disruption");
        set_ac(5, "holy");
        set_ac(5, "plasma");
        set_ac(2, "infernal");
        set_material("misc/silk");
    set_limbs( ({ "torso" }) );
}

