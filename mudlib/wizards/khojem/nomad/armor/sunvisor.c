//  Wizard:  Khojem
//  sunvisor
//  sunvisor.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("sunvisor");
    set("id", ({ "visor", "sunvisor", "metal visor"}) );
    set("short", "a metal sunvisor");
    set("long", "The metal visor is worn across the face.  Numerous small holes "+
      "perforate the metal and allow fair vision, but protects you from the "+
      "harse glare off the desert sands.  The visor also provides good "+
      "protection during battle.");
    set_weight(1);
    set_value(20);
    set_type("visor");
    set_ac(12);
        set_ac(0, "aether");
        set_ac(0, "depression");
        set_ac(1, "acid");
        set_ac(1, "vacuum");
        set_ac(12, "fire");
        set_ac(12, "cold");
        set_ac(6, "impact");
        set_ac(2, "stress");
        set_ac(6, "strike");
        set_ac(12, "cutting");
        set_ac(12, "impaling");
        set_ac(0, "electricity");
        set_ac(0, "time");
        set_ac(8, "crushing");
        set_ac(1, "disruption");
        set_ac(1, "holy");
        set_ac(0, "plasma");
        set_ac(1, "infernal");
    set_limbs( ({ "head" }) );
}
