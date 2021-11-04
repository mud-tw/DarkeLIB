//  Khojem
//  Longsword
//  long_sword.c

inherit "/std/weapon";

create() {
    ::create();
    set_ac(4);
    set("id", ({ "long sword", "longsword", "sword" }));
    set("short", "longsword");
    set("long", "The mainstay of the fighter's arsenal, the "+
      "longsword is crafted from choice steel.  It's edge is "+
      "sharp, and its point allows stabbing attacks."
    );
    set_type("blade");
    set_quality(3);
    set_wc(10, "cutting");
    set_wc(6, "impaling");
    set_verb("slice");
    set_parry_bonus(5);
    set_weight(90);
    set_value(145);
    return;
}

