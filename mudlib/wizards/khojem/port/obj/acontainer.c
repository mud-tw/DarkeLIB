//  Wizard:  Khojem
//  The genaric dock worker container
//  acontainer.c
 
#include <std.h>

inherit OBJECT;

void init() {
  :: init();
  add_action("zopen","open");
}

void create() {
  ::create();
  set_name("crate");
  set_id( ({ "crate" }));
  set_short("a wooden crate");
  set_long("A wooden crate used to hold something.  It is stamped "+
    "with the name of a distant city.");
  set_weight(400);
}

int zopen(string ztext) {
  int qual,flag;
  object obj;
  string str;
  if(ztext!="crate") { return 0; }
  qual = 2 + random(5);
  flag = random(50)+1;
    if(flag == 1) {
      obj=new("/d/damned/virtual/broad-sword_"+qual+".weapon");
      str="a broad sword";
    }
    if(flag == 2) {
      obj=new("/d/damned/virtual/long-sword_"+qual+".weapon");
      str="a long sword";
    }
    if(flag == 3) {
      obj=new("/d/damned/virtual/dagger_"+qual+".weapon");
      str="a dagger";
    }
    if(flag == 4) {
      obj=new("/d/damned/virtual/footman's-mace_"+qual+".weapon");
      str="a footman's mace";
    }
    if(flag == 5) {
      obj=new("/d/damned/virtual/battle-axe_"+qual+".weapon");
      str="a battle axe";
    }
    if(flag == 6) {
      obj=new("/d/damned/virtual/hand-axe_"+qual+".weapon");
      str="a hand axe";
    }
    if(flag == 7) {
      obj=new("/d/damned/virtual/footman's-flail_"+qual+".weapon");
      str="a footman's flail";
    }
    if(flag == 8) {
      obj=new("/d/damned/virtual/broad-sword_"+qual+".weapon");
      str="a broad sword";
    }
    if(flag == 9) {
      obj=new("/d/damned/virtual/glaive_"+qual+".weapon");
      str="a glaive";
    }
    if(flag == 10) {
      obj=new("/d/damned/virtual/halberd_"+qual+".weapon");
      str="a halberd";
    }
    if(flag == 11) {
      obj=new("/d/damned/virtual/bastard-sword_"+qual+".weapon");
      str="a bastard sword";
    }
    if(flag == 12) {
      obj=new("/d/damned/virtual/short-sword_"+qual+".weapon");
      str="a short sword";
    }
    if(flag == 13) {
      obj=new("/d/damned/virtual/two-handed-sword_"+qual+".weapon");
      str="a two handed sword";
    }
    if(flag == 14) {
      obj=new("/d/damned/virtual/great-axe_"+qual+".weapon");
      str="a great axe";
    }
    if(flag == 15) {
      obj=new("/d/damned/virtual/quarter-staff_"+qual+".weapon");
      str="a quarter staff";
    }
    if(flag == 16) {
      obj=new("/d/damned/virtual/morning-star_"+qual+".weapon");
      str="a morning star";
    }
    if(flag == 17) {
      obj=new("/d/damned/virtual/scimitar_"+qual+".weapon");
      str="a scimitar";
    }
    if(flag == 18) {
      obj=new("/d/damned/virtual/war-hammer_"+qual+".weapon");
      str="a war hammer";
    }
    if(flag == 19) {
      obj=new("/d/damned/virtual/hammer_"+qual+".weapon");
      str="a hammer";
    }
    if(flag == 20) {
      obj=new("/d/damned/virtual/military-pick_"+qual+".weapon");
      str="a military pick";
    }
    if(flag == 21) {
      obj=new("/d/damned/virtual/spear_"+qual+".weapon");
      str="a spear";
    }
    if(flag == 22) {
      obj=new("/d/damned/virtual/trident_"+qual+".weapon");
      str="a trident";
    }
    if(flag == 23) {
      obj=new("/d/damned/virtual/breast-plate.armour");
      str="a breast plate";
    }
    if(flag == 24) {
      obj=new("/d/damned/virtual/corslet.armour");
      str="a corslet";
    }
    if(flag == 25) {
      obj=new("/d/damned/virtual/chain-coif.armour");
      str="a chain coif";
    }
    if(flag == 26) {
      obj=new("/d/damned/virtual/scale-greaves.armour");
      str="some scale greaves";
    }
    if(flag == 27) {
      obj=new("/d/damned/virtual/iron-greaves.armour");
      str="some iron greaves";
    }
    if(flag == 28) {
      obj=new("/d/damned/virtual/scale-mail.armour");
      str="scale mail armour";
    }
    if(flag == 29) {
      obj=new("/d/damned/virtual/chain-greaves.armour");
      str="some chain greaves";
    }
    if(flag == 30) {
      obj=new("/d/damned/virtual/chain-mail.armour");
      str="chain mail armour";
    }
    if(flag == 31) {
      obj=new("/d/damned/virtual/studded-leather-jacket.armour");
      str="a studded leather jacket";
    }
    if(flag == 32) {
      obj=new("/d/damned/virtual/studded-leather-vest.armour");
      str="a studded leather vest";
    }
    if(flag == 33) {
      obj=new("/d/damned/virtual/studded-leather-pants.armour");
      str="some studded leather pants";
    }
    if(flag == 34) {
      obj=new("/d/damned/virtual/leather-jacket.armour");
      str="a leather jacket";
    }
    if(flag == 35) {
      obj=new("/d/damned/virtual/leather-pants.armour");
      str="some leather pants";
    }
    if(flag == 36) {
      obj=new("/d/damned/virtual/leather-vest.armour");
      str="a leather vest";
    }
    if(flag == 37) {
      obj=new("/d/damned/virtual/great-helm.armour");
      str="a great helm";
    }
    if(flag == 38) {
      obj=new("/d/damned/virtual/cloak.armour");
      str="a cloak";
    }
    if(flag == 39) {
      obj=new("/d/damned/virtual/cloth-pants.armour");
      str="some cloth pants";
    }
    if(flag == 40) {
      obj=new("/d/damned/virtual/wall-shield.armour");
      str="a wall shield";
    }
    if(flag == 41) {
      obj=new("/d/damned/virtual/large-shield.armour");
      str="a large shield";
    }
    if(flag == 42) {
      obj=new("/d/damned/virtual/small-shield.armour");
      str="a small shield";
    }
    if(flag == 43) {
      obj=new("/d/damned/virtual/buckler-shield.armour");
      str="a buckler shield";
    }
    if(flag == 44) {
      obj=new("/d/damned/virtual/gauntlet.armour");
      str="a gauntlet";
    }
    if(flag == 45) {
      obj=new("/d/damned/virtual/chain-glove.armour");
      str="a chain glove";
    }
    if(flag == 46) {
      obj=new("/d/damned/virtual/iron-bracer.armour");
      str="an iron bracer";
    }
    if(flag == 47) {
      obj=new("/d/damned/virtual/studded-leather-glove.armour");
      str="a studded leather glove";
    }
    if(flag == 48) {
      obj=new("/d/damned/virtual/boiled-leather-glove.armour");
      str="a boiled leather glove";
    }
    if(flag == 49) {
      obj=new("/d/damned/virtual/leather-glove.armour");
      str="a leather glove";
    }
    if(flag == 50) {
      obj=new("/d/damned/virtual/padded-glove.armour");
      str="a padded leather glove";
    }
  write("You have found "+str+".");
  say(this_player()->query_cap_name()+" opens a crate and finds "+str+".");
  obj->move(this_player());
  write("The crate disintegrates after you open it.");
  say("The crate in "+this_player()->query_cap_name()+"'s hands "+
    "disintegrates.");
  this_object()->remove();
}
