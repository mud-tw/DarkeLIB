//  Wizard:  Khojem
//  quest sash - nutnux quest
//  quest_sash.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("pink sash");
    set("id", ({ "sash", "pink sash", "nutnux_quest_ob" }) );
    set("short", "a pink sash");
    set("long", "A wide, pink sash made of silk and worn around the waist.");
    set_weight(40);
    set_value(0);
    set_type("belt");
    set_ac(1);
    set_limbs( ({ "torso" }) );
}
