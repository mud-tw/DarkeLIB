//  Wizard:  Khojem
//  Fir'nvillee Rock
//  rock.c
 
#include <std.h>

inherit OBJECT;
 
void create() {
  ::create();
    set_name("rock");
    set_id( ({ "rock" }) );
    set_short("a rock");
    set_long("It is a huge, ancient rock inscribed with the runes:\n"+
    "\nFir'nvillee Woods\n\nAll those who enter must abide by the\n"+
    "laws of King Fir'burger, Lord of this realm.\n\n"+
    "Fir'nvillee brought to you by the Wizard Khojem\n");
    set_weight(9999);
    set_value(0);
}
