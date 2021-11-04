//  Khojem
//  Palace Guard's Polearm
//  polearm.c

inherit "/std/weapon";

create() {
    ::create();
    set_ac(3);
    set("id", ({ "fork", "military fork", "polearm" }));
    set("short", "military fork");
    set("long", "This is a long pole with a fork at the end.");
    set_type("two handed polearm");
    set_quality(3);
    set_wc(12, "impaling");
    set_verb("stab");
    set_parry_bonus(-10);
    set_weight(150);
    set_value(60);
    return;
}

