//  Wizard:  Khojem
//  Half-Orc Chief's Chair
//  chief_chair.c
 
#include <std.h>

inherit OBJECT;

 
void create() {
  ::create();
    set_name("Half-Orc Chief's Throne");
    set_id( ({ "throne", "chair" }) );
    set_short("Half-Orc Chief's Throne");
    set_long("The throne is crudely made from hewed logs and bound by twine.");
    set_weight(1000);
    set_value(10);
}
