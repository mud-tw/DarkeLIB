// Wizard:  Khojem
// waterbottle
// waterbottle.c

#include <std.h>;

inherit OBJECT;

int strength;
int intox;
int drinks_left;

int full() { return drinks_left; }

void create() {
  :: create();
  strength = 0;
  drinks_left = 4;
  intox = 0;
  set_id(({ "waterbottle", "bottle" }));
  set_name("waterbottle");
  set("long", "It is a large bottle with a cork at one end."
  );
  set_weight(5);
  set_value(10);
  return;
}

string query_short() {
  switch(drinks_left) {
    case  4    : return "waterbottle is (full)";
    case  3    : return "waterbottle is (mostly full)";
    case  2    : return "waterbottle is (semi-full)";
    case  1    : return "waterbottle is (nearly empty)";
    default    : return "waterbottle is (empty)";
  }
}

void fill(string id, int drink, int alc) {
  strength  = drink;
  intox     = alc;
  set_value(100+alc);
  drinks_left = 4;
  set_weight(5 + (4 * drinks_left));
  say(this_player()->query_cap_name()+" fills a waterbottle.\n");
  return;
}

void empty() {
  set_weight(5);
  set_value(10);
  drinks_left = 0;
  strength    = 0;
  intox       = 0;
  return;
}

void init() {
  :: init();
  add_action("drink_me","drink");
  add_action("pour_me", "pour");
  add_action("pour_me", "empty");
  return;
}

int pour_me(string str) {
  if(present(str,this_player()) != this_object()) return 0;
  if(drinks_left == 0) return 0;
  write("You empty the contents of a lwaterbottle.\n");
  say(this_player()->query_cap_name()+" empties a waterbottle.\n");
  this_object()->empty();
  return 1;
}

int drink_me(string str) {
  if(present(str,this_player()) != this_object()) return 0;
  if(drinks_left < 1) {
    write("Hmmm...   it is empty.\n");
    return 1;
  }
  write("You slurp the contents of the waterbottle.\n");
  say(this_player()->query_cap_name()+" drinks from a waterbottle.\n");
  this_player()->add_quenched(strength);
  this_player()->add_intox(intox);
  this_player()->add_mp(intox/10);
  drinks_left--;
  if(drinks_left > 0)
    set_weight(5 + (4 * drinks_left));
  else
    this_object()->empty();
  return 1;
}
  

