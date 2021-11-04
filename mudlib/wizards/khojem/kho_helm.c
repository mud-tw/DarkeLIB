//  Khojem
//  Khojem's Helm
//  kho_helm.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("helm");
    set("id", ({ "helm", "helmet", "khojem's helm" }) );
    set("short", "Khojem's helm");
    set("long", "This looks like Khojem's favorite helm.");
    set_weight(375);
    set("value", 50000);
    set_type("helmet");
    set_limbs( ({ "head" }) );
    set_ac(5);
    set_wear( (: call_other, this_object(), "extra_worn" :) );
    set_remove( (: call_other, this_object(), "extra_removed"  :) );
}

int extra_worn() {
    this_player()->set_invis();
    write("Looks like you just went invis\n");
	return 1;
}

int extra_removed() {
    this_player()->set_invis();
    write("Looks like you just became vis\n");
    return 1;
}
