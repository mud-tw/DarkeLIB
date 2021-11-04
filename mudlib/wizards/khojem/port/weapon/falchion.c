//  Khojem
//  blue-steeled falchion
//  falchion.c

inherit "/std/weapon";

create() {
    ::create();
    set_name("falchion");
    set_ac(4);
    set("id", ({ "sword", "falchion", "blue-steeled falchion" }));
    set("short", "blue-steeled falchion");
    set("long", "A broad-bladed sword with a slightly curved edge.  "
    );
    set_type("blade");
    set_quality(6);
    set_wc(16, "cutting");
    set_wc(4, "impaling");
    set_verb("slice");
    set_parry_bonus(7);
    set_weight(105);
    set_decay_rate(400);
    set_material("metal/blued steel");
    set_value(185);
}
