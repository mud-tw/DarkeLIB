//  Wizard:  Khojem
//  veil
//  veil.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("silk veil");
    set("id", ({ "silk veil", "veil" }) );
    set("short", "a silk veil");
    set("long", "A silky, sheer veil that is worn to mask the lower face.");
    set_weight(4);
    set_value(40);
    set_type("visor");
    set_material("misc/silk");
    set_ac(1);
    set_limbs( ({ "head" }) );
}

