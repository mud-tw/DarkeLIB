//  Wizard:  Khojem
//  hash pipe
//  hash_pipe.c

#include <std.h>

inherit OBJECT;

void create() {
  ::create();
  set_name("hash pipe");
  set_id( ({ "pipe", "hash pipe", "hashish pipe" }) );
  set_short("An unlit hashish pipe");
  set_long("A hashish pipe.  Light up with 'light pipe', "+
	"smoke it with 'smoke pipe'");
  set_weight(10);
  set_value(200);
  return;
}

void remove() {
  write("Your pipe goes out and disappears.\n");
  ::remove();
}

void init() {
  ::init();
  add_action("light", "light");
  add_action("smoke", "smoke");
  return;
}

void set_property(string str, mixed val) {
  if(str != "quality") {
    ::set_property(str, val);
    return;
  }
  ::set_property(str, val);
  if(intp(val)) set_value(10 + 3*val);
  return;
}


int light(string str) {
  if(str && present(str, this_player()) == this_object()) {
    if(query("lit")) return notify_fail("It is already lit!\n");
    set("lit", 1);
    set("puffs", 15);
    write("You light up.");
    message("info", this_player()->query_cap_name() + " lights up.",
	all_inventory(environment(this_player())),
	({ this_player() }));
    set_short("A lit hashish pipe");
    call_out("remove", 240);
    return 1;
  }
  return 0;
}

int smoke(string str) {
  if(str && present(str, this_player()) == this_object()) {
    if(!query("lit")) return notify_fail("Light it first!\n");
    write("You inhale the smoke into your lungs and hold your breath for awhile.");
    if(!this_player()->add_stoned(props["quality"] * 10))
      write("You are so wasted, further smoking will do no good.");
    message("info", this_player()->query_cap_name() + " takes a long draw "+
	"from a hashish pipe.",all_inventory(environment(this_player())),
	({ this_player() }));
    set("puffs", query("puffs") - 1);
    if(query("puffs") <= 0) remove();
    return 1;
  }
  return 0;
}
