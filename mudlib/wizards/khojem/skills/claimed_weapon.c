#include <clock.h>

inherit "/std/spells/long_term_spell";

void create() {
    ::create();
    set_property("name","claimed weapon");
    set_property("skill","enchantment");
    set_property("duration", "permanent");
    set_property("casting time",4);
    set_property("base mp cost",25);
    set_property("dev cost", 16);
    set_property("fast dev cost", 45);
    set_property("spell level", 3);
    set_property("moon","luna");
    set_property("caster message","You begin to claim the weapon.");
    set_property("target message","");
    set_property("observer message","$C begins to enchant a weapon.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
message("help",
"This is a very powerful enchantment which allows enchanters to effectively "
"use their creations.  When cast on a weapon, the weapon is bound to the caster.  "
"If anyone besides the caster attempts to use the weapon, it will hit as if "
"the wielder had NO SKILL with the weapon at all.  If the enchanter who cast the spell "
"wields the weapon, however, he/she will have good skill with the weapon "
"REGARDLESS of what weapon skills the enchanter has!  In a nutshell, this spell "
"gives a single enchanter FREE skill with that weapon.  However, this effect is not "
"always on.  You must activate it like a locked enchantment ('help spell lock enchantment').  "
"\nThe syntax for the activation is:\n"
"'activate claim on <weapon>'\n"
"Where <weapon> is the target weapon.  If you wish to see how often this "
"enchantment may be activated, type 'help <weapon>'.  The power of the spell "
"affects how often you can invoke the enchantment and how much "
"free skill with the weapon you receive.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  int time, mod;
  if(!at->is_weapon()) {
    message("info", "You must cast this spell on a weapon.",
	    caster);
	  caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(!mapp(at->query_enchantments())) {
    message("info", "That item may not receive locked enchantments.",
	    caster);
	  caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(at->query_property("claimed by")) {
    message("info", "That weapon is already claimed.",
	    caster);
	  caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(flag) {
    message("info", "You misdirect the energies of the spell and shatter "+
	    "the item!", caster);
    message("info", (string)caster->query_cap_name() +
	    " inadvertently shatters the item.",
	    environment(caster), ({ caster }) );
    at->remove();
    remove();
    return;
  }
  set_work_message("%^CYAN%^You enchant the weapon.");
  time = 600+80*power;
  mod = 30+2*props["spell level"];
  start_work(at, caster, (time*mod)/caster->query_skill("enchantment"), power);
  
  return;
}

void finish_work(object caster, object at, int power) {
  int ench;
  mixed extra;

  if(power <= 0) {
    message("info", "BUG in Enchanter spell....unable to complete.",
	    environment(caster));
    remove();
    return;
  }
  message("info", "You are finished enchanting.  Type 'help <item>' to list the enchantments.", caster);
  message("info", (string)caster->query_cap_name() + " utters some "+
	  "magical incantations.",
	  environment(caster), ({ caster }) );
	at->add_enchantment("claim", "claim activate", power,
	  3600 / (power/2+1), 0);
	if(strsrch((string)at->query_type(), "two handed") > -1)
	  at->set_type("two handed "+(string)caster->query_name()+" claimed");
	else
	  at->set_type((string)caster->query_name()+" claimed");
	message("info", "See the help on this spell to see how to "
	  "activate the claimed weapon.", caster);
	at->set_property("claimed by", (string)caster->query_name());
	extra = at->query_property("extra long");
	if(!extra) extra = ({});
	else if(stringp(extra)) extra = ({ extra });
	else if(!pointerp(extra)) extra = ({});
	extra += ({ "%^CYAN%^This weapon is claimed by %^RESET%^%^BOLD%^"+
	  (string)caster->query_name() });
  remove();
  return;
}

