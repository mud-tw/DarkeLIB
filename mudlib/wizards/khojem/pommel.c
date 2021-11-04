// Wizard:  Khojem
// test pommel
// pommel.c

inherit OBJECT;

void init() {
  :: init();
  add_action("do_connect","connect");  // usage:  connect pommel
}

void create() {
  :: create();
  set_name("pommel");
  set_id("pommel");
  set_short("pommel");
  set_long("A round pommel that is not connected to a sword.");
  set_value(50);
  set_weight(100);
  set_material("/metal/eonmite");
}

int do_connect(string str) {
  if(str!="pommel") { return 0; }
  this_object()->remove();
  return 1;
}
