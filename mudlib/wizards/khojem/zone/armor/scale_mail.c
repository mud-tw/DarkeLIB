//  Khojem
//  Scale Mail Vest
//  scale_mail.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("scale mail");
    set("id", ({ "mail", "scale mail" }) );
    set("short", "A scale mail vest");
    set("long", "This armour is made of thin circles of metal "+
      "that held together by leather covering the torso.");
    set_weight(250);
    set("value", 180);
    set_type("body armour");
    set_limbs( ({ "torso" }) );
    set_ac(9);
}
