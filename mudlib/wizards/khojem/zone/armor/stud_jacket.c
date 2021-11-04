//  Khojem
//  Studded Leather Jacket
//  stud_jacket.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("studded-leather-jacket");
    set("id", ({ "jacket", "leather jacket", "studded jacket",
     "studded leather jacket" }) );
    set("short", "A studded leather jacket");
    set("long", "This jacket is crafted of boiled leather and "+
      "covers the torso and arms.");
    set_weight(90);
    set("value", 75);
    set_type("armour");
    set_limbs( ({ "torso", "right arm", "left arm" }) );
    set_ac(7);
}

