//  Khojem
//  Chain Coif Helmet
//  stud_pants.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("chain coif");
    set("id", ({ "coif", "chain coif", "helmet", "hood" }) );
    set("short", "A chain coif");
    set("long", "This coif is draped over the head, and "+
      "provides protection against attack.");
    set_weight(25);
    set("value", 35);
    set_type("helmet");
    set_limbs( ({ "head" }) );
    set_ac(8);
}

