//  Khojem
//  Studded Leather Pants
//  stud_pants.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("studded-leather-pants");
    set("id", ({ "pants", "leather pants", "studded pants",
     "studded leather pants" }) );
    set("short", "A pair of studded leather pants");
    set("long", "These pants are crafted of boiled leather "+
     "with metal studs.");
    set_weight(130);
    set("value", 120);
    set_type("pants");
    set_limbs( ({ "right leg", "left leg" }) );
    set_ac(7);
}

