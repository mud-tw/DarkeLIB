//  Wizard:  Khojem
//  muddy boots
//  muddy_boots.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("muddy boots");
    set("id", ({ "boots", "muddy boots" }) );
    set("short", "muddy boots");
    set("long", "A fine, sturdy pair of leather boots.  They are caked in mud.");
    set_weight(40);
    set_value(60);
    set_type("boots");
    set_limbs( ({ "right foot", "left foot" }) );
    set_ac(10);
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
