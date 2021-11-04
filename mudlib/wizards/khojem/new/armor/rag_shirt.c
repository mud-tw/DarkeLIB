//  Wizard:  Khojem
//  rag shirt
//  rag_shirt.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("rag shirt");
    set("id", ({ "shirt", "rag shirt" }) );
    set("short", "A rag shirt");
    set("long", "A leather rag shirt crudely tanned from the skin "
      "of a deer.  It is caked with mud and grime.  It is lice ridden."
    );
    set_weight(100);
    set_value(1);
    set_type("armour");
    set_limbs( ({ "torso", "right arm", "left arm" }) );
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
