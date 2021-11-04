//  Wizard:  Khojem
//  Wooden Crown
//  wooden_crown.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("wooden crown");
    set("id", ({ "crown", "wooden crown" }) );
    set("short", "wooden crown");
    set("long", "A polished wooden crown made of elm wood.");
    set_weight(30);
    set("value", 300);
    set_type("helmet");
    set_limbs( ({ "head" }) );
    set_ac(5);
    set_wear( (: call_other, this_object(), "extra_worn" :) );
    set_remove( (: call_other, this_object(), "extra_remove" :) );
}

int extra_worn(){
  int  zwisdom;
  say(this_player()->query_cap_name()+" wears a wooden crown.",
    this_player());
  zwisdom=(int)this_player()->query_stats("wisdom");
  this_player()->set_stats("wisdom",(zwisdom+1));
  return 1;
}

int extra_remove(){
  int zwisdom;
  say(this_player()->query_cap_name()+" removes a wooden crown.",
    this_player());
  zwisdom=(int)this_player()->query_stats("wisdom");
  this_player()->set_stats("wisdom",(zwisdom-1));
  return 1;
}

remove() {
  int zwisdom;
  zwisdom=(int)this_player()->query_stats("wisdom");
  this_player()->set_stats("wisdom",(zwisdom-1));
  return::remove();
}
