//  Khojem
//  Studded Leather Jacket
//  stud_jacket.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("studded-leather-gloves");
    set("id", ({ "studded glove", "studded leather glove", 
      "leather glove", "glove", "glove",
    }) );
    set("short", "A studded leather glove.");
    set("long", "This is a boiled leather glove with studs in it.");
    set_weight(3);
    set("value", 6);
    set_type("glove");
    set_limbs( ({ "right hand", "left hand" }) );
    set_ac(7);
}

