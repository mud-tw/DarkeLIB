inherit "/std/skills/long_term.c";

int skill, ll, ol;
string name, door;
object lock;

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(25);
    set_fast_dev_cost(60);
    set_property("no target", 1);
}

void info() {
message("help",
"This skill is used to install a lock on doors, chests, safes, or lockers.\n"
"This difficulty of the lock varies with the skill of the craftsman.  "
"This is a long-term skill ('help long-term') and takes much real time to "
"use.  If interrupted, you may pick up the skill again later "
"by 'use'-ing the skill again.\n"
"Syntax (chest): use install lock at <item> with <player>\n"
"where player is who the lock will be keyed to. (with no player"
" name it defaults to the tinker.)\n"
"Syntax (door): use install lock at <door name> \n",
	this_player());
}

void skill_func(object from, object at, string arg) {
  int time;
  string tmp,who;

  if(sscanf(arg,"%s with %s",arg,tmp) != 2) tmp=from->query_name();
  at=present(arg,environment(from));
  if(!at && !environment(from)->query_lock_level(arg)) {
    message("info","You cannot install a lock in that.",from);
    remove();
    return;
  }
  name = lower_case(tmp);
  who = sprintf("%s/%s/%s", "/adm/save/users", name[0..0], name);
  if( (file_size(who + ".o") < 0) ) {
    message("info", "That person does not exist.",from);
    remove();
    return;
  }
  if(at) {
    if(!at->query_is_locker()) {
      message("info", "This skill must be used on a chest or door.", from);
      remove();
      return;
    }
    if(!at->query_lock_level()) {
      message("info", "That item has a ruined lock which may not be repaired.",from);
      remove();
      return;
    }
    ol = at->query_lock_level();
    skill = props["skill level"];
// At 5% skill, lock level = 12, at 100% lock level = 50.
    ll = skill * 2 / 5 + 10;
    if(ol > (ll + 5)) {
      message("info","This lock is beyond your skill to rework.",from);
      remove();
      return;
    }
    else if(ol > ll) {
      message("info","You try to rework the lock, but end up ruining it.",from);
      at->set_lock_level(1000);
      at->set_lock("locked");
      at->set_key("shadowraith chest key");
      remove();
      return;
    }
  }
  else {
    at=environment(from);
    door = arg;
    ol = at->query_lock_level(door);
    skill = props["skill level"];
// At 5% skill, lock level = 12, at 100% lock level = 50.
    ll = skill * 2 / 5 + 10;
    if(ol > (ll + 5)) {
      message("info","This lock is beyond your skill to rework.",from);
      remove();
      return;
    }
    else if(ol > ll) {
      message("info","You try to rework the lock, but end up ruining it.",from);
      at->set_lock_level(door,0);
      at->set_locked(door,0);
      remove();
      return;
    }
  }
    
    while(shadow(at, 0)) shadow(at, 0)->external_destruct(shadow(at, 0));
    skill = props["skill level"];
    time = 300 + (skill * 15);
    if(time > 1800) time = 1800;
    message("info", "%^CYAN%^%^BOLD%^You begin installing the lock.", from);
    set_work_message("%^CYAN%^You tinker with the lock.");
    start_work(at, from, time);
    return;
}

void finish_work(object from, object at) {
  int i;
    
  message("info", "%^CYAN%^%^BOLD%^You finish installing the lock.",
    from);
  if(at->query_is_locker()) {
    at->set_lock("unlocked");
    at->set_lock_level(ll);
    at->set_key(name+" chest key");
    message("info","You craft a key for the new lock.",from);
    remove();
    return;
  }
  else {
    at->set_locked(door,0);
    at->set_lock_level(door,ll);
    at->rewrite_castle();
    remove();
    return;
  }
}
  
