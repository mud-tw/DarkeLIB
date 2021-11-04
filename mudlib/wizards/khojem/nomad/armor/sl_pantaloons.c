//  Wizard:  Khojem
//  slited pantaloons
//  slited pantaloons.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("slited pantaloons");
    set("id", ({ "pantaloons", "slited pantaloons" }) );
    set("short", "slited pantaloons");
    set("long", "A pair of darke, silk pantaloons.  A sequined panties with long "+
      "silken sheets that cover, yet reveal much of the leg and banded "+
      "at the ankles.");
    set_weight(20);
    set_value(100);
    set_type("pants");
    set_limbs(({ "right leg", "left leg" }));
    set_material("misc/silk");
    set_ac(1);
}

