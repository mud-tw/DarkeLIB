//  Wizard:  Khojem
//  traveller's compass
//  compass.c
 
#include <std.h>

inherit OBJECT;

void init(){
  ::init();
  add_action("do_compass","use");
}
 
void create() {
  ::create();
    set_name("traveller's compass");
    set_id( ({ "traveller's compass", "compass" }) );
    set_short("traveller's compass");
    set_long("A small metal compass with a floating needle that "+
      "always points to Akkad.");
    set_weight(100);
    set_value(2800);
}

int do_compass(string str) {
  object ob;
  if(str != "compass" && str != "traveller's compass") {return 0;}
  write("The traveller's compasses humms and then dissolves away.\n"+
    "You feel yourself being lifted away.  All goes black...\n");
  say(this_player()->query_cap_name()+" fumbles with the "+
    "traveller's compass and suddenly disappears.\n");
  this_player()->
    move(find_object_or_load("/d/damned/akkad/ak_center"));
  write("\nYou materialize.\n");
  this_object()->remove();
  return 1;
}
