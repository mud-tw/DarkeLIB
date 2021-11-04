//  Wizard:  Khojem
//  bodice
//  bodice.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("silk bodice");
    set("id", ({ "silk bodice", "bodice" }) );
    set("short", "a silk bodice");
    set("long", "A luxurious, silk bodice that is worn about the torso.");
    set_weight(15);
    set_value(200);
    set_type("body armor");
    set_ac(2);
        set_ac(1, "aether");
        set_ac(1, "depression");
        set_ac(1, "acid");
        set_ac(1, "vacuum");
        set_ac(2, "fire");
        set_ac(2, "cold");
        set_ac(1, "impact");
        set_ac(1, "stress");
        set_ac(1, "strike");
        set_ac(2, "cutting");
        set_ac(2, "impaling");
        set_ac(1, "electricity");
        set_ac(1, "time");
        set_ac(2, "crushing");
        set_ac(1, "disruption");
        set_ac(1, "holy");
        set_ac(1, "plasma");
        set_ac(1, "infernal");
        set_material("misc/silk");
    set_limbs( ({ "torso" }) );
}

