//  Wizard:   Khojem
//  Monster:  Wood-Elf Lackey - he serves the wood-elf mage
//  File:     commoner.c

#include <std.h>

inherit MONSTER;

varargs void say_this(string str, object whom);

create() {
  object money;
  ::create();
    set_name("drunken lackey");
    set_id( ({ "lackey","elf", "wood-elf lackey"}) );
    set_level(5);
    set_short("wood-elf lackey");
    set_long("It appears the wood-elf lackey has had a bit too much to drink.  "+
      "He sits at one of the tables.  Right now his forehead is resting on "+
      "table-top.  He appears to be sleeping right now, but the bottle next "+
      "to his head will be ready for when he wakes up." 
      );
    set("race", "wood-elf");
    set_gender("male");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_property("melee damage", ([ "crushing" : 10]));
    set_skill("melee", 20);
    set_skill("dodge", 20);
    set_stats("dexterity", 30);
    set_stats("intelligence", 60);
    set_wimpy(30);
    set_alignment(0);
    set_languages(({"common", "elvish", "drow", "middle-english" }));
    set_lang_prof("elvish",10);
    set_lang_prof("drow",8);
    set_lang_prof("middle-english",8);
    money=new("std/obj/coins");
    money->set_money("silver",(random(20)));
    money->move(this_object());
    set_emotes(2, ({
	  "The drunk elf wakes up and raises his head slowly.\n"+
	    "He lets out a moan and rests his head down on the table.\n"+
	    "He is immediately asleep, again.",
	  "The drunken elf snores loudly.",
	  "The drunken elf coughs in his sleep.",
	}),0);
}

void directed_message(object whom, string cmd) {
  string who, what, p1, p2;

  who  = (string)whom->query_cap_name();
  if(sscanf(cmd,"%sdead rose%s",p1,p2) == 2){
    say_this("A dead rose?  Oh, yes.  That damn faerie always held onto a "+
      "dead rose.",whom);
  }
  if(sscanf(cmd,"%sfaerie%s",p1,p2) == 2) {
    what="I hate that faerie and it hates me!  I think it hates everyone!  "+
      "Every day that damn mage made me go into the basement to feed that "+
      "evil, foul-spawned faerie.";
    say_this(what,whom);
  }
  if(sscanf(cmd,"%smage%s",p1,p2) == 2) {
    what="That mage is the evilest and vilest of all the wood-elves here "+
      "in Fir'nvillee.  I have served her for years and know well her ways.  "+
      "She pays me enough to drink away my misery here at Barfir's.";
    say_this(what,whom);
  }
  if(sscanf(cmd,"%sbasement%s",p1,p2) == 2){
    what="Yes.  That sick mage has a secret trapdoor beneath her hut.  "+
      "A ladder leads down to a chamber beneath the forest floor.  That's "+
      "where she imprisons that evil faerie she captured years ago.";
    say_this(what,whom);
  }
  if(sscanf(cmd,"%strapdoor%s",p1,p2) == 2){
    what="The trapdoor is magical!  But, I will tell you...  Just rap on "+
      "the floor with your fist!  On the third rap... it will open for you...  "+
      "I hope you kill that witch of a faerie!";
    say_this(what,whom);
  }
  return;
}

varargs void say_this(string str, object whom) {
  string your_lang;

  write("\nThe lackey raises his head.");
  say("\nThe lackey raises his head.");
  if(objectp(whom))
    your_lang = (string)whom->query_primary_lang();
  if(your_lang && stringp(your_lang) &&
    (int)this_object()->query_lang_prof(your_lang)
     >= 8) force_me("speak "+your_lang);
  else force_me("speak common");
  force_me("say "+str);
  write("The lackey's head slams back to the tabletop.\n");
  say("The lackey's head slams back to the tabletop.\n");
  return;
}

void catch_tell(string str) {
  string lang;

  if(sscanf(str, "%*s says something in %s.", lang) == 2 && random(2)) {
    say_this("I don't understand "+lang+".");
    return;
  }
}


