//  Wizard:  Khojem
//  Leather Gloves
//  leather_gloves.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("leather gloves");
    set("id", ({ "gloves", "leather gloves" }) );
    set("short", "pair of leather gloves");
    set("long", "A pair of tanned, leather gloves.");
    set_weight(2);
    set("value", 10);
    set_type("glove");
    set_limbs( ({ "right hand", "left hand" }) );
    set_ac(4);
}
