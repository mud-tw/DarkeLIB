//  Khojem
//  blue-steeled trident
//  trident.c

inherit "/std/weapon";

create() {
  int qual;
    ::create();
    set_name("trident");
    set_ac(4);
    set("id", ({ "trident", "blue-steeled trident" }));
    set("short", "blue-steeled trident");
    set("long", "A long steel pole wrapped with leather strapping with a "+
      "massive, barbed fork at one end."
    );
    set_type("two handed polearm");
    set_quality(6);
    set_wc(22, "impaling");
    set_verb("jab");
    set_parry_bonus(-15);
    set_weight(120);
    set_decay_rate(400);
    set_material("metal/blued steel");
    set_value(100);
}
