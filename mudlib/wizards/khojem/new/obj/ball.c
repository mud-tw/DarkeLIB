//  Wizard:  Khojem
//  Ball
//  ball.c
 
#include <std.h>

inherit OBJECT;

 
void create() {
  string zcolor;
  ::create();
    set_name("ball");
    set_id( ({ "ball" }) );
    set_short("a ball");
    switch(random(3)){
      case 0:zcolor="blue";break;
      case 1:zcolor="red";break;
      case 2:zcolor="green";break;
    }
    set_long("A small "+zcolor+" ball made of animal skin.");
    set_weight(1);
    set_value(0);
}

