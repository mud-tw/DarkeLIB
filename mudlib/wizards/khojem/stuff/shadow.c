inherit "/std/monster";
void create()
   {
    object ob;
    ::create();
    ob = new("/std/skills/invisibility_art");
    set_name("shadow");
    set("id", ({ "darkness", "shadow" }));
    set("short", "Shadow");
    set("long",
        "The shadow is hard to see even while you " +
         " look directly at it. Its eyes are hollow.");
    set("aggressive", 0);
    set_level(20);
    set_exp(4000000);
    set_overall_ac(180);
    set_property("enhance criticals",-3);
    set_body_type("human");
    set_alignment(0);
    set("race", "shadow");
    set_gender("male");
    set_stats("strength", 80);
    set_stats("dexterity", 150);
    set_stats("constitution", 100);
    set_stats("wisdom", 110);
    set_stats("intelligence", 130);
    set_stats("charisma", 0);
    set_skill("melee", 140);
    set_skill("attack", 170);
    set_skill("dodge", 150);
    set_property("magic resistance", 85);
    set_skill("martial_arts", 120);
    set_skill("shadow",200);
    set_skill("invisibility art",200);
    set_skill("concentrate", 100);
    set_skill("conjuration", 100);
    set_skill("perception",110);
    set_skill("resist stun", 100);
    set_spell_level("lightning bolt", 6);
    add_spell("lightning bolt","$A");
    set_combat_chance(100);
set_property("melee damage", ([
        "electricity" : 60,
        "cold" : 70 ]) );
   set_max_hp(10000);
   set_max_mp(10000);
   set_hp(10000);
   set_mp(10000);
    ob->do_skill(this_object(), 0);
   }

void init() {
  ::init();
  if(this_player()->is_player() && !query("stalking"))
    delayed_call("start_stalk", 1, this_player());
  return;
   }
     void start_stalk(object who) {
     object ob;
     if(query("stalking")) return;
     if(!who || environment(who) != environment()) return;
     ob = new("/std/skills/shadow");
     ob->do_skill(this_object(), (string)who->query_name());
     set("stalking", 1);
     return;
   }
