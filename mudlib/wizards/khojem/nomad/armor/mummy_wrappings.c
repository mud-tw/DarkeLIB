//  Wizard:  Khojem
//  mummy wrappings
//  mummy_wrappings.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("mummy wrappings");
    set("id", ({ "wrappings", "mummy wrappings", "rags" }) );
    set("short", "mummy wrappings");
    set("long", "The old, dust-covered cloth wrappings retch of "+
      "embalming fluid and decaying flesh.");
    set_weight(30);
    set_value(10);
    set_type("armour");
    set_material("misc/cotton");
    set_ac(1);
    set_limbs( ({ "torso" }) );
}
