inherit "/std/guilds/guildmaster_obj";

void create() {
  ::create();
  set_name("paladin object");
  set_id(({ "guildmaster object", "paladin object", "symbol" }) );
  set_short("The symbol of the Paladin Guildmaster");
  set_long(
"Type 'help guildmaster' for instructions.");
  set_join_room("/d/damned/guilds/join_rooms/paladin_join");
  return;
}
