//  Khojem
//  Halberd
//  halberd.c

inherit "/std/weapon";

create() {
    ::create();
    set_ac(3);
    set("id", ({ "halberd", "polearm" }));
    set("short", "halberd");
    set("long", "It is a long polearm with an axe-like blade "+
      "at the end.  At the end of the blade is a long point "+
      "for piercing."
    );
    set_type("two handed polearm");
    set_quality(3);
    set_wc(15, "cutting");
    set_wc(8, "impaling");
    set_verb("chop");
    set_parry_bonus(-5);
    set_weight(275);
    set_value(145);
    return;
}

