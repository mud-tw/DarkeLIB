//  Wizard:  Khojem
//  wooden spear
//  wooden_spear.c

inherit "/std/weapon";

create() {
    ::create();
    set_name("wooden spear");
    set("id", ({ "wooden spear", "spear" }));
    set("short", "wooden spear");
    set("long", "A long, carved wood branch honed to a sharp point."
    );
    set_type("two handed polearm");
    set_quality(random(4)+1);
    set_wc(15, "impaling");
    set_verb("stab");
    set_parry_bonus(-10);
    set_ac(4);
    set_weight(350);
    set_value(300);
}
