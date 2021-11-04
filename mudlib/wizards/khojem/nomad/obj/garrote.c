// Wizard:  Khojem
// garrote
// garrote.c

#include <move.h>

inherit "/std/Object";

void init() {
     ::init();
  add_action("do_it","use");
}

void create() {
  ::create();
  set_name("garrote");
  set_id(({ "garrote" }) );
  set_short("a garrote");
  set_long("The garrote is a thin, sharp wire with a wooden handle attached "+
    "attached to each end."
  );
}

int do_it(string str) {
  write(">>> "+str+"\n");
  if(str != "garrote") { return 0; }
  return 1;
}

