//  Wizard:  Khojem
//  Leather Bracer
//  leather_bracer.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("leather bracer");
    set("id", ({ "bracer", "leather bracer" }) );
    set("short", "leather bracer");
    set("long", "A tanned, leather bracer worn on the arm.");
    set_weight(50);
    set("value", 60);
    set_type("bracer");
    set_limbs( ({ "right arm", "left arm" }) );
    set_ac(5);
}
