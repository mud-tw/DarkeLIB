//  Wizard:  Khojem
//  Skillet
//  skillet.c

inherit "/std/weapon";

create() {
    ::create();
    set_name("skillet");
    set_ac(2);
    set("id", ({ "skillet" }));
    set("short", "skillet");
    set("long", "A huge, cast-iron skillet crusted with burnt bits of food."
    );
    set_type("blunt");
    set_quality(2);
    set_wc(5, "crushing");
    set_verb("pound");
    set_parry_bonus(-10);
    set_weight(100);
    set_value(50);
}
