//  Khojem
//  Bastard Sword
//  bastard_sword.c

inherit "/std/weapon";

create() {
    ::create();
    set_ac(4);
    set("id", ({ "bastard sword", "sword" }));
    set("short", "bastard sword");
    set("long", "This two-handed sword has a thick, heavy blade and a "+
      "sharp thrusting point."
    );
    set_type("two handed blade");
    set_quality(3);
    set_wc(14, "cutting");
    set_wc(6, "impaling");
    set_verb("slice");
    set_parry_bonus(2);
    set_weight(150);
    set_value(220);
    return;
}
