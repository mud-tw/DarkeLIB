//  Wizard:  Khojem
//  Gold Ring
//  gold_ring.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("gold ring");
    set("id", ({ "ring", "gold ring" }) );
    set("short", "gold ring");
    set("long", "A simple, polished gold ring.  Maybe one of the hareem "+
      "girls thought she'd get lucky with Chief Moped.");
    set_weight(5);
    set("value", 100);
    set_type("ring");
    set_limbs( ({ ({ "right hand", "left hand", 
      "first branch", "second branch", "third branch", "fourth branch" }) }) );
    set_material("metal/gold");
    set_ac(1);
}
