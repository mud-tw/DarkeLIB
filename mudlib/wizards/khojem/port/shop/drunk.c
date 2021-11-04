//  Wizard:   Khojem
//  Monster:  town drunk
//  File:     drunk.c

#include <std.h>

inherit MONSTER;
 
create() {
  ::create();
    set_name("drunk");
    set_id( ({ "drunk","sailor", "town drunk", "relg", "Relg", "half-orc" }) );
    set_level(3);
    set_short("relg, the town drunk");
    set_long("Relg is a crusty, old sailor.  His face is rutty and hasn't been "+
      "shaved in days.  His clothes are old and worn.  Fresh vomit runs down the "+
      "one side of his tunic.  It appears he has been drinking here for a long "+
      "time.  His eyes are glazed and his lip hangs low to the right side of his "+
      "mouth.  Once he was probably an adventuresome sailor, but now he cannot get "+
      "work on any ships that dock at port."
      );
    set("race", "half-orc");
    set_gender("male");
    set_body_type("human");
    set_overall_ac(4);
    set_property("melee damage", ([ "crushing" : 5]));
    set_languages(({"common", "orchish" }));
    set_lang_prof("common",9);
    set_lang_prof("orchish",9);
    set_primary_lang("common");
    set_emotes(1, ({
	  "Relg's head weaves as he looks into the bottom of another empty tankard.",
	  "Relg's head rolls back and he stares at the ceiling with slited eyes.",
	  "Relg retches on the floor.",
	  "Relg belches and looks for more ale.",
	  "Relg belches and looks for more ale.",
	  "Relg belches and looks for more ale.",
	}),0);
    set_speech(1,"common",({ 
	  "Knya spar' a cupper for an ol' sarlr, mate?",
	  "Knya spar' a cupper for an ol' sarlr, mate?",
	  "Knya spar' a cupper for an ol' sarlr, mate?",
	  "Knya spar' a cupper for an ol' sarlr, mate?",
	  "Argh!  End meee 'nothr ale, lad!",
	  "Argh!  End meee 'nothr ale, lad!",
	  "Argh!  End meee 'nothr ale, lad!",
	  "Argh!  End meee 'nothr ale, lad!",
	  "Ey' ders 'nothr gol' chip in 'arbor ey'd herd.",
	}),0);
}
 
void catch_tell(string str) {
  int steal_amt,amt;
  string a;
  object ob1;
  if(sscanf(str, "%s enters.", a) == 1) {
    a = lower_case(a);
    ob1 = present(a, environment(this_object()));
    if(ob1) {
      if(ob1->query_invis()) { return; }
      if(ob1->query_stealth() >= 30) { return; }
      steal_amt=random(10);
      if(steal_amt>3) {
        steal_amt = random(10) + 50;
        amt = (int)ob1->query_money("silver");
        if(amt > steal_amt) {
          this_object()->add_money("silver",steal_amt);
          steal_amt = steal_amt * -1;
          ob1->add_money("silver",steal_amt);
        }
        steal_amt = random(10);
        amt = (int)ob1->query_money("gold");
        if(amt > steal_amt){
          this_object()->add_money("gold",steal_amt);
          steal_amt = steal_amt * -1;
          ob1->add_money("gold",steal_amt);
        }
        return;
      }
      return;
    }
  }
  return;
}
