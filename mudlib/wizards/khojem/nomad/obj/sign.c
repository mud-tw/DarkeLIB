//  Wizard:  Khojem
//  sign
//  sign.c
 
#include <std.h>

inherit OBJECT;

void create() {
  ::create();
    set_name("sign");
    set_id( ({ "sign" }) );
    set_short("a sign");
    set_long("A wooden sign is planted in the sand.");
    set_weight(9000);
    set_value(0);
}
