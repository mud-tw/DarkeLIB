//  Wizard:  Khojem
//  Wooden Shield
//  wood_shield.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("wooden shield");
    set("id", ({ "shield", "wooden shield" }) );
    set("short", "A wooden shield");
    set("long", "A rectangular, wooden shield thatched with bark over wood bracing.");
    set_weight(80);
    set_value(40);
    set_type("shield");
    set_limbs( ({ ({ "right hand", "left hand", "first branch", 
      "second branch", "third branch", "fourth branch" }) }) );
    set_ac(10);
        set_ac(0, "aether");
        set_ac(0, "depression");
        set_ac(1, "acid");
        set_ac(0, "vacuum");
        set_ac(1, "fire");
        set_ac(5, "cold");
        set_ac(20, "impact");
        set_ac(1, "stress");
        set_ac(16, "strike");
        set_ac(1, "electricity");
        set_ac(1, "time");
        set_ac(1, "disruption");
        set_ac(1, "holy");
        set_ac(1, "plasma");
        set_ac(1, "infernal");
        set_material("wood/oak");
}
