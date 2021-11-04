//  Wizard:  Khojem
//  rag pants
//  rag_pants.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("rag pants");
    set("id", ({ "pants", "rag pants" }) );
    set("short", "rag pants");
    set("long", "Crudely tanned, leather pants.  They are caked in mud and "+
      "have holes in the knees.");
    set_weight(140);
    set_value(1);
    set_type("pants");
    set_limbs( ({ "right leg", "left leg" }) );
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
