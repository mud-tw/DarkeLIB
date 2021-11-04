//  Wizard:  Khojem
//  leather chemise
//  chemise.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("leather chemise");
    set("id", ({ "chemise", "leather chemise" }) );
    set("short", "leather chemise");
    set("long", "The leather chemise is a one-piece shift.  It would "+
      "hang freely over the bosom.");
    set_weight(20);
    set("value", 40);
    set_type("cloak");
    set_limbs( ({ "torso" }) );
    set_ac(1);
    set_material("misc/soft leather");
}
