//  Wizard:  Khojem
//  ruby jewel
//  ruby_jewel.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("ruby jewel");
    set("id", ({ "ruby", "jewel", "ruby jewel" }) );
    set("short", "a ruby jewel");
    set("long", "The ruby jewel is worn in the navel.  It attracts light and "+
      "shines a brillant, glintering red.");
    set_weight(5);
    set_value(6000);
    set_type("belt");
    set_limbs(({ "torso" } ));
    set_material("misc/of a jewel stone");
    set_ac(1);
}

