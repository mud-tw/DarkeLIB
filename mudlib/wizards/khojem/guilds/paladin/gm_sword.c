#include <std.h>

inherit "/std/weapon";
inherit AUTOLOAD;

create() {
    ::create();
    set_ac(20);
    set_name("sword");
    set("id", ({ "sword", "guildmaster sword", "holy avenger", "avenger" }));
    set("short", "The Legendary Holy Avenger");
    set("long", 
"The Holy Avenger glows with a pure inner light.  The sword is exquisitely"
"crafted and you have never seen it's equal in beauty.");
   set_type("blade");
    set_quality(6);
    set_property("no add quality",1);
    set_property("no decay", 1);
   set_wc(30,"cutting");
    set_wc(15, "impaling");
    set_wc(15, "holy");
    set_verb("slice");
    set_parry_bonus(5);
    set_property("hit bonus", 15);
    set_property("enchantment",15);
    set_enh_critical(1);
   set_weight(250);
    set_value(150000);
    return;
}


int query_always_keep() { return 1; }
