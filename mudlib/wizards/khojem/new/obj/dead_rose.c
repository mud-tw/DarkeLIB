//  Wizard:  Khojem
//  Dead Rose - Gnome Hermit Quest
//  dead_rose.c
 
#include <std.h>

inherit OBJECT;

 
void create() {
  ::create();
    set_name("dead rose");
    set_id( ({ "dead rose", "rose", "flower", "dead flower",
      "dead_rose_quest_ob" }) );
    set_short("a dead rose");
    set_long("The bloom of this dead rose was lost long ago.");
    set_weight(2);
    set_value(0);
}
