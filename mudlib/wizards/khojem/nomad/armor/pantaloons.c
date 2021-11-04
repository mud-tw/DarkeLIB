//  Wizard:  Khojem
//  silk pantaloons
//  pantaloons.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("silk pantaloons");
    set("id", ({ "pantaloons", "silk pantaloons" }) );
    set("short", "silk pantaloons");
    set("long", "A pair of luxurious, silk pantaloons.  A sequined panties with long "+
      "silken sheets that cover the legs and banded "+
      "at the ankles.");
    set_weight(80);
    set_value(400);
    set_type("pants");
    set_limbs(({ "right leg", "left leg" }));
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
}

