//  Wizard:  Khojem
//  Leather Belt
//  leather_belt.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("leather belt");
    set("id", ({ "belt", "leather belt" }) );
    set("short", "a leather belt");
    set("long", "A thick, leather belt made from animal skin.");
    set_weight(20);
    set_value(3);
    set_type("belt");
    set_ac(5);
        set_ac(0, "aether");
        set_ac(0, "depression");
        set_ac(1, "acid");
        set_ac(1, "vacuum");
        set_ac(2, "fire");
        set_ac(2, "cold");
        set_ac(2, "impact");
        set_ac(1, "stress");
        set_ac(1, "strike");

        set_ac(1, "electricity");
        set_ac(0, "time");
        set_ac(3, "crushing");
        set_ac(1, "disruption");
        set_ac(0, "holy");
        set_ac(1, "plasma");
        set_ac(1, "infernal");
    set_material("misc/leather");
    set_limbs( ({ "torso" }) );
}
