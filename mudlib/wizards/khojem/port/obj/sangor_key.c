//  Wizard:  Khojem
//  Sangor Key
//  sangor_key.c
 
#include <std.h>

inherit OBJECT;
 
void create() {
  ::create();
    set_name("sangor key");
    set_id( ({ "sangor key", "key" }) );
    set_short("sangor key");
    set_long("A large heavy key with elaborate scroll-work on its handle.\n");
    set_weight(10);
    set_value(0);
}
