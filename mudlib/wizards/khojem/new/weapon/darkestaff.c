//  Wizard:  Khojem
//  Darkestaff
//  darkestaff.c

inherit "/std/weapon";

int lit;

void init() {
	add_action("do_illum","illuminate");
	add_action("do_darken","darken");
	add_action("do_help","help");
	::init();
}

void create() {
    ::create();
    set_ac(6);
    set_name("darkestaff");
    set("id", ({ "darkestaff", "staff" }));
    set("short", "darkestaff, it humms");
    set("long", "A long, darkwood staff used to bash opponents.  "+
      "Its wood is as dark as the darkest night and is over six "+
      "feet in length.  The shaft is covered with cryptic runes.  "+
      "It humms with a mysterious energy."
    );
    set_type("two handed staff");
    set_quality(6);
    set_wc(16, "crushing");
    set_verb("bash");
    set_parry_bonus(12);
    set_weight(300);
    set_value(10);
    set_property("magic item", ({"illuminate", "darken"}));
}

int do_illum(string str) {
  if(!id(str)) {
    notify_fail("Illuminate what?\n");
    return 0;
  }
  if(lit) {
    notify_fail("The darkestaff is already illuminated!\n");
    return 0;
  }
  write("The darkestaff's humm briefly intensifies.\n"+
    "A loud thunderclap emits from the staff!\n"+
    "Suddenly, a brilliant, bright blue light beams out\n"+
    "from one end and the entire area is awash with light.\n"
  );
  say(this_player()->query_cap_name()+" utters some cryptic "+
    "words and the darkestaff hums loudly.\n"+
    "The hum is subdued by a loud thunderclap!\n"+
    "A brilliant, radianting blue light beams out from its end\n"+
    "and the entire area is awash in its blue light!\n",
    this_player());
  environment(this_object())->set_property("light", 2);
  lit=1;
  return 1;
}

int do_darken(string str) {
  if(!id(str)) {
    notify_fail("Darken what?\n");
    return 0;
  }
  if(!lit){
    notify_fail("The darkestaff is not lit!\n");
    return 0;
  }
  if(!lit) {
    notify_fail("The darkestaff is lit!\n");
    return 0;
    }
  write("Suddenly!  A thunderclap emits from the darkestaff!\n"+
    "The darkestaff's blue light disappears.\n"
  );
  say(this_player()->query_cap_name()+" utters some cryptic words.\n"+
    "A loud thunderclap emits from the darkestaff!\n"+
    "The darkestaff's blue light dissappears!\n",
    this_player()
  );
  environment(this_object())->set_property("light", -2);
  lit = 0;
  return 1;
}

string query_short(){
  string str;
  
  str = ::query_short();
  if(lit) str = str+ " and emits a strong, brilliant blue light!";
  return str;
}

int move(mixed dest) {
  int x;
  
  if(lit) environment(this_object())->set_property("light", -2);
  x = :: move(dest);
  if(lit) environment(this_object())->set_property("light", 2);
  return x;
}

int query_lit() { return lit; }

int remove() {
  if(lit) environment(this_object())->set_property("light", -2);
  return ::remove();
}


int do_help (string str) {
  if(str!="darkestaff") return 0;
  if((this_player()->query_skill("detect magic")) < random(100)) return 0;
  write("Light Source\nilluminate darkestaff or darken darkestaff\n");
  return 1;
}

