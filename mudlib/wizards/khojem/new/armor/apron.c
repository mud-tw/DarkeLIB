//  Wizard:  Khojem
//  Leather Apron
//  apron.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("leather apron");
    set("id", ({ "apron", "leather apron" }) );
    set("short", "leather apron");
    set("long", "A tanned leather apron soiled with grease and animal entails.");
    set_weight(200);
    set_value(3);
    set_type("armour");
    set_limbs( ({ "torso" }) );
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
        set_material("misc/leather");
}
