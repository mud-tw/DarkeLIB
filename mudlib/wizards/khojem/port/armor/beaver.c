//  Wizard:  Khojem
//  beaver
//  beaver.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("beaver");
    set("id", ({ "visor", "beaver", "iron beaver"}) );
    set("short", "iron beaver");
    set("long", "The beaver is a grilled-piece of iron that protects the lower "+
      "portion of your face.");
    set_weight(20);
    set_value(40);
    set_type("visor");
    set_ac(15);
    set_limbs( ({ "head" }) );
        set_ac(1, "aether");
        set_ac(1, "depression");
        set_ac(5, "acid");
        set_ac(1, "vacuum");
        set_ac(10, "fire");
        set_ac(10, "cold");
        set_ac(5, "impact");
        set_ac(1, "stress");
        set_ac(10, "strike");
        set_ac(15, "cutting");
        set_ac(5, "impaling");
        set_ac(1, "electricity");
        set_ac(1, "time");
        set_ac(10, "crushing");
        set_ac(1, "disruption");
        set_ac(1, "holy");
        set_ac(1, "plasma");
        set_ac(1, "infernal");
        set_material("metal/iron");
}
