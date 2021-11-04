// Wizard:  Khojem
// monolith 3
// mono3.c

#include <move.h>

inherit "/std/Object";

void init() {
     ::init();
  add_action("do_mono","read");
}

int move(object dest) {
  if(living(dest)) return MOVE_NOT_ALLOWED;
  else return ::move(dest);
}

void create() {
  ::create();
  set_name("monolith3");
  set_id(({ "darke monolith","monolith" }) );
  set_short("a darke monolith");
  set_long("The darke, black monolith stands upright out of the rock before "+
    "the structure.  The rock's surface is near translucent.  It is finely "+
    "crafted from a single, huge rock.  Cryptic letters are raised upon its "+
    "surface.  Perhaps you can read it."
  );
}

int clean_up() { return 0; }

int do_mono(string str) {
  if(str != "monolith" && str != "darke monolith")
    return 0;
  else
    write("Darke Temple of the Order of the Blessed Return\n\n"+
      "This phase of the area is not open yet\n"+
      "Finger Khojem to check on its availability.\n"
    );
    return 1;
}
