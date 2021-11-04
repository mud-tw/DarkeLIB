//  Wizard:  Khojem
//  simple canvass bag
//  bag.c


inherit "/std/bag_logic";

int lock_container(string null) { return 0; }

int unlock_container(string null) { return 0; }

void create() {
  ::create();
  set_name("canvas bag");
  set_id(({ "canvas bag", "bag" }));
  set_short("a large, canvas bag");
  set_long("This large, canvas bag may be used to store items, adding "
    "no weight to you.");
  set_weight(20);
  set_max_internal_encumbrance(1000);
  set_value(140);
  return;
}

mixed query_property(string str) {
  if(str != "no save") return ::query_property(str);
  if(all_inventory(this_object()) &&
    sizeof(all_inventory(this_object()))) return 1;
  return 0;
}
