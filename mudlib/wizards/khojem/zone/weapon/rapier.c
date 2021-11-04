//  Khojem
//  Rapier
//  rapier.c

inherit "/std/weapon";

create() {
    ::create();
    set_ac(3);
    set("id", ({ "rapier" }));
    set("short", "rapier");
    set("long", "This short, two-edged sword with a narrow pointed blade "+
      "is prized by all well-skills swordsman and fighters."
    );
    set_type("blade");
    set_quality(3);
    set_wc(7, "cutting");
    set_wc(4, "impaling");
    set_verb("slice");
    set_parry_bonus(8);
    set_weight(80);
    set_value(120);
    return;
}

