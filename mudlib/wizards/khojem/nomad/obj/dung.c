//  Wizard:  Khojem
//  dung
//  dung.c
 
#include <std.h>

inherit OBJECT;
 
void create() {
  ::create();
    set_name("dung");
    set_id( ({ "dung", "human excrement", "shit" }) );
    set_short("a pile of dung");
    set_long("The large pile of human excrement is covered with flies.  "+
      "The nomads could easily cut a latrine in the sand but instead "+
      "opt to use this basket!");
    set_weight(50);
    set_value(0);
}
