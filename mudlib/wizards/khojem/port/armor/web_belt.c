//  Wizard:  Khojem
//  Web Belt
//  web_belt.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("web belt");
    set("id", ({ "belt", "web belt" }) );
    set("short", "a web belt");
    set("long", "A wide, web belt made from sturdy cloth.");
    set_weight(18);
    set_value(4);
    set_type("belt");
    set_material("misc/cotton");
    set_ac(4);
        set_ac(0, "aether");
        set_ac(0, "depression");
        set_ac(1, "acid");
        set_ac(1, "vacuum");
        set_ac(3, "fire");
        set_ac(4, "cold");
        set_ac(4, "impact");
        set_ac(1, "stress");
        set_ac(1, "strike");
        set_ac(1, "electricity");
        set_ac(0, "time");
        set_ac(4, "crushing");
        set_ac(2, "disruption");
        set_ac(0, "holy");
        set_ac(1, "plasma");
        set_ac(1, "infernal");
    set_limbs( ({ "torso" }) );
}

