//  Khojem
//  jeweled epee
//  epee.c

inherit "/std/weapon";

create() {
    ::create();
    set_name("jeweled epee");
    set_id(({ "foil", "sword", "blade", "epee", "jeweled epee" }));
    set_short("jeweled epee");
    set_long("The epee has a bowl-shaped guard to protect the "+
	  "wielder's hand.  It is a rigid, triangular shaped blade "+
	  "that tapers to a sharp point.  A few jewels can be seen imbeded "+
	  "in its hilt.\n");
    set_weight(95);
    set_value(1990);
    set_wc(18,"cutting");
    set_wc(10,"impaling");
    set_parry_bonus(12);
    set_ac(8);
    set_type("blade");
    set_quality(6);
    set_decay_rate(600);
    set_material("metal/fine tempered steel");
}
