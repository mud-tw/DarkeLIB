//  Khojem
//  blackjack
//  blackjack.c

inherit "/std/weapon";

create() {
    ::create();
    set_name("blackjack");
    set_ac(4);
    set("id", ({ "blackjack", "jack", "blunt" }));
    set("short", "blackjack");
    set("long",
      "The blackjack has a springy leather handle with a looped, "
      "strap at the handle's end.  Above the handle the leather "
      "broadens and lead shot is enclosed within the leather.  "
      "A heavy blow to the back of the neck will probably crush "
      "a person's spine."
    );
    set_type("blunt");
    set_quality(6);
    set_wc(15, "crushing");
    set_verb("pound");
    set_parry_bonus(-15);
    set_weight(120);
    set_value(40);
    set_hit_bonus(4);
    set_material("misc/leather");
}
