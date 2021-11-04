//  Wizard:  Khojem
//  purse
//  purse.c


inherit "/std/bag_logic";

int lock_container(string null) { return 0; }

int unlock_container(string null) { return 0; }

void create() {
  ::create();
  set_name("purse");
  set_id(({ "leather purse", "purse", "bag" }));
  set_short("a leather purse");
  set_long("A small, soft-skinned leather purse.");
  set_weight(5);
  set_max_internal_encumbrance(100);
  set_value(20);
  return;
}

mixed query_property(string str) {
  if(str != "no save") return ::query_property(str);
  if(all_inventory(this_object()) &&
    sizeof(all_inventory(this_object()))) return 1;
  return 0;
}
