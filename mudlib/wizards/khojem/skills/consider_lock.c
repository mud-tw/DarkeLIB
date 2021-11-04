
inherit "/std/skills/skill";

function pick_func;
mixed pick_arg;
string name;
object shad;

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(19);
    set_fast_dev_cost(56);
    set_property("no target", 1);
}

void info() {
message("help",
"By using the consider lock skill, the crafty thief can closely examine "
"a lock to determine its strength.  The better the score in this skill, "
"the more accurate the estimate.  A magnifying glass must be used in "
"conjunction with the consider lock skill.",
this_player());
}

void skill_func(object from, object at, string arg) {
  int lock_lev, skill_lev, lock_quot, modifier;
  object ob;
  string desc;

  ob = present(arg, environment(from));
  if(!ob && !environment(from)->query_locked(arg)) {
    message("info", 
    "There is no locked door or object of that description here.",
    from);
    remove();
    return;
  }
/*  if(!present("magnifying glass", from)) {
    message("info", "You need a magnifying glass to use this skill.", from);
    remove();
    return;
  }*/
  if(ob) {
     if(member_array("std/bag_logic.c", deep_inherit_list(ob)) < 0) {
        message("info", "That doesn't have a lock.", from);
        remove();
        return;
     }
     if(!ob->query_locked()) {
        message("info", "It is not locked!", from);
        remove();
        return;
     }
     lock_lev = (int)ob->query_lock_level();
     name = lower_case((string)ob->query_short());
  }
  else
     lock_lev = environment(from)->query_lock_level(arg);

  if(lock_lev < 1) {
     message("info", "There is an error with the lock.  Mail Duridian immediately,\n"+
                     "indicating what kind of lock you were considering (chest/safe/door/etc.)\n"+
                     "and in which room you were considering the lock.", from);
     remove();
     return;
  }

/*  if((time() - (int)from->query_last_use("consider lock")) < MINUTE {
     message("info",
"Your eyes begin to tear as you look at the lock.  It seems that you need\n"+
"to rest your eyes for a moment before examining another lock.",
            from);
    remove();
    return;
  }
*/
  from->set_last_use("consider lock");
  seteuid(geteuid(this_object()));

  message("info", "You kneel down and peer at the lock.", from);
  if(ob) 
     message("info",(string)from->query_cap_name()+" kneels down for a moment "+
         "and peers at the lock on "+name+".", environment(from), ({ from }) );
  else
     message("info",(string)from->query_cap_name()+" kneels down for a moment "+
         "and peers at the lock on a door.", environment(from), ({ from }) );

  skill_lev = (int)from->query_skill("consider lock");
  lock_quot = (int)this_player()->query_skill("pick locks") / lock_lev;
  switch(skill_lev) {
     case 1..25: modifier = 5; break;
     case 26..50: modifier = 4; break;
     case 51..75: modifier = 2; break;
     case 76..100: modifier = 1; break;
     case 101..10000: modifier = 0; break;
     default: write("DAMNIT!  You hit a bug in consider lock's *FIRST* SWITCH statement.  Please mail Duridian ASAP!");
              remove();
              return;
  }

  if(modifier) {
     lock_quot -= 2*modifier;
     lock_quot += random(2*modifier + 1);
  }

  switch(lock_quot) {
     case -100..0: desc = "no chance whatsoever of"; break;
     case 1..3: desc = "an extremely difficult time"; break;
     case 4..7: desc = "a very difficult time"; break;
     case 8..11: desc = "quite a difficult time"; break;
     case 12..15: desc = "a moderately difficult time"; break;
     case 16..18: desc = "some trouble"; break;
     case 19..22: desc = "a little trouble"; break;
     case 23..25: desc = "a fairly easy time"; break;
     case 26..1000: desc = "a very easy time"; break;
     default: write("DAMNIT!  You hit a bug in consider lock's *SECOND* SWITCH statement.  Please mail Duridian ASAP!");
              remove();
              return;
  }

  write("After having gazed at the lock for a moment, you guess that you would "+
        "have "+desc+" picking open this lock.");
  remove();
  return;
}
