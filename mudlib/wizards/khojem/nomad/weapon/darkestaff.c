//  Wizard:  Khojem
//  Darkestaff
//  darkestaff.c

inherit "/std/weapon";

int lit;
object shadow;

void init() {
	add_action("do_illum","illuminate");
	add_action("do_darken","darken");
	add_action("do_help","help");
	::init();
}

create() {
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
    set_type("two handed blunt");
    set_quality(6);
    set_wc(16, "crushing");
    set_verb("bash");
    set_parry_bonus(12);
    set_weight(300);
    set_value(2000);
    lit = 0;
    shadow = 0;
}

int do_illum(string str) {
  if(!str || present(str, this_player()) != this_object()) {
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
  seteuid(getuid());
  say(this_player()->query_cap_name()+" utters some cryptic "+
    "words and the darkestaff hums loudly.\n"+
    "The hum is subdued by a loud thunderclap!\n"+
    "A brilliant, radianting blue light beams out from its end\n"+
    "and the entire area is awash in its blue light!\n",
    this_player());
    shadow = new("/std/spells/shadows/light_shad");
    shadow->set_light(2);
    shadow->start_shadow(environment());
    lit=1;
    return 1;
}

int do_darken(string str) {
  if(!str || present(str, this_player()) != this_object()) {
    notify_fail("Darken what?\n");
    return 0;
  }
  if(!lit){
    notify_fail("The darkestaff is not lit!\n");
    return 0;
  }
  if(!lit) {
    notify_fail("The darkestaff is not illuminated!\n");
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
  if(shadow) shadow->external_destruct(shadow);
  lit = 0;
  return 1;
}

int do_help (string str) {
  if(str!="darkestaff") return 0;
  if((this_player()->query_skill("detect magic")) < random(100)) return 0;
  write("Light Source\nilluminate darkestaff or darken darkestaff\n");
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
  
 
    if(lit && shadow)
      shadow->external_destruct(shadow);
    x = ::move(dest);
    if(lit) {
      seteuid(getuid());
      shadow = new("/std/spells/shadows/light_shad");
      shadow->set_light(2);
      shadow->start_shadow(environment());
    }
    return x;
}

int query_lit() { return lit; }

remove() {
   if(lit && shadow)
      shadow->external_destruct(shadow);
   return ::remove();
}
