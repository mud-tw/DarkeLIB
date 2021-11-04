// Wizard:  Khojem
// Wooded Stream
// vat.c

#include <move.h>

inherit "/std/Object";

int move(object dest) {
  if(living(dest)) return MOVE_NOT_ALLOWED;
  else return ::move(dest);
}

void create() {
  ::create();
  set_name("stream");
  set_id(({ "stream", "water" }) );
  set_short("A clear running stream");
  set_long("A clear running stream is flowing here.  The water is moving "+
    "very fast.  Fortunately, the path does not force you to cross the stream."
  );
}

void init() {
  ::init();
  add_action("fill_vessel", "fill");
  return;
}

int fill_vessel(string str) {
  object ob;

  ob = present(str, this_player());
  if(!ob) {
    write("You don't have "+article(str)+".");
    return 1;
  }
  if(!ob->id("water skin")) {
    write("You can't fill "+article(str)+" with water!");
    return 1;

  }
  if(ob->full()) {
    write("That waterskin is full already.");
    return 1;
  }
  ob->fill("water", 5, 0);
  write("You fill the waterskin.");
  message("other_action", (string)this_player()->query_cap_name() +
	  " fills a waterskin with water from the vat.",
	  environment(this_player()), ({ this_player() }) );
  return 1;
}

int clean_up() { return 0; }

