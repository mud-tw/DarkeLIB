// Khojem 10/19/96

inherit "/std/locker_room";

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit("/d/damned/guilds/paladin/meeting", "up");
   set("short","The Paladin Treasury");
   set("long",
     "Here in the cellar of the castle is the Paladin Treasury.  "
     "Paladins may store items here, but they are available for "
     "all paladins.\nMAKE SURE you close a chest after using it, "
     "or the itmes inside may be lost.\n
   );
}

