// Wizard:  Khojem
// captain's diary
// diary.c

#include <move.h>

inherit "/std/Object";

void create() {
  ::create();
  set_name("sapphire");
  set_id(({ "sapphire" }) );
  set_short("a gleeming sapphire");
  set_long("It is a small sapphire.  Light is refracted within the jewel and "+
    "glimmers and shines.\n"
  );
  set_weight(1);
  set_value(4000);
}
