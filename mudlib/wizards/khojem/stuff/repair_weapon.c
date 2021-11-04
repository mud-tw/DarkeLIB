inherit "/std/skills/skill";

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(11);
    set_fast_dev_cost(27);
    set_property("target type", "any");
    set_property("must be present", 1);
}

void info() {
message("help",
"This spell may be used to keep weapons in good repair.  "
"Weapons go down in quality after repeated usage, but repairing "
"them periodically can delay, or even prevent this loss.  Note that "
"once the weapon has lost a quality level, this skill WILL NOT increase "
"the quality back to the original level, only delay further decay.",
this_player());
}


void skill_func(object from, object at, string arg) {
  int max, rep;
  
  if(!at->is_weapon()) {
    message("info", "That is not a weapon!", from);
    remove();
    return;
  }
  if(from->query("repair weapon")) {
    message("info", "You can only do that once at a time.", from);
    remove();
    return;
  }
  max = (int)at->query_decay_rate();
  max -= props["skill level"] * max /100;
  if(max < 0) max = 0;
  if(!at->query_decay_status() || (int)at->query_decay_status() <= max) {
    message("info", "You have repaired that weapon as much as your skill allows.",
      from);
    remove();
    return;
  }
  max = (int)at->query_decay_rate() * props["skill level"] / 100;
  rep = (props["skill level"]/2 + random(props["skill level"]/2))*(max - (int)at->query_decay_status()) / 100;
  message("info", "%^CYAN%^%^BOLD%^You begin repairing the weapon...", from);
  message("info", "%^CYAN%^"+(string)from->query_cap_name() + " begins repairing a weapon.",
      environment(from), ({ from }));
  from->set("repair weapon", 1);
  call_out("repair", 10, rep, at, from);
  return;
}

void repair(int rep, object at, object from) {
  if(from) from->set("repair weapon", 0);
  if(!present(at, from) && !present(at, environment(from))) {
    message("info", "%^CYAN%^%^BOLD%^You have lost the weapon...the skill fails.",
        from);
    remove();
    return;
  }
  message("info", "%^CYAN%^%^BOLD%^You complete the repairs.", from);
  message("info", "%^CYAN%^"+(string)from->query_cap_name() + " finishes repairing a weapon.",
      environment(from), ({ from }));
  at->repair(rep);
  remove();
  return;
}

