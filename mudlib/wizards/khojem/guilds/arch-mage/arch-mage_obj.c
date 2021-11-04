inherit "/std/guilds/guildmaster_obj";

void create() {
  ::create();
  set_name("arch-mage object");
  set_short("The symbol of the Arch-Mage Guildmaster");
  set_id(({ "guildmaster object", "arch-mage object", "symbol" }) );
  set_long(
"This symbol takes the form of a small bejeweled wand.  Type "
"'help guildmaster' for help.");
  set_join_room("/d/damned/guilds/join_rooms/arch-mage_join");
  return;
}

