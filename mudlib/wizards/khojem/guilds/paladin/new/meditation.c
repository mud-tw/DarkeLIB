//      Paladin Meditation Room
//      meditation.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
  set_property("light", 2);
  set_property("indoors", 1);
  set("short", "Paladin Meditation Room");
  set("long", 
    "The meditation room is a place were paladins prepare for battle.  "
    "It is a small room with a simple altar mounted with a small "
    "silver cross.  To both sides of the cross is a narrow shelf "
    "lined with wax candles that light the east wall.  The floor "
    "is constructed of a parqueted pattern of oak which helps "
    "deafen your footsteps.  A few  kneel posts form rows "
    "facing the simple altar.\n" 
  );
  add_exit("/d/damned/guilds/paladin/meeting","west");
  set_items(([
    ({ "floor", "oak floor", "parquet floor" }) :
       "The parqueted oak floor is highly polished and well "
       "maintained by the servants who serve the castle in "
       "reverent servitude to their god.",
    ({ "silver cross", "cross" }) :
       "The simple silver cross is highly polished and unadorned.  "
       "Its smooth surface reflects the light of the many candles "
       "at its base and flanking its sides.  As you gaze into the "
       "candle's flaming reflection from its surface you begin to "
       "ponder how your deeds and actions reflect upon those you "
       "meet and interact.",
    ({ "kneel posts", "kneel post" }) :
       "The simple oak kneel posts are a few inches off the oak "
       "floor.  They are scratched and pitted by the armour of "
       "the numerous paladins that have prayed here before you "
       "in preparation for their battle against evil.",
    ({ "simple alter", "altar", "candles", "candle", "oak shelf" }) :
       "The altar is a simple oak shelf with a smooth silver "
       "cross centered against the east wall.  At the base of "
       "the cross and flanking it to both sides are a large "
       "number of lit white candles.  Occasionally, a robed, "
       "hooded monk silently enters and replaces the candles "
       "before they burn out.",
  ]));
}

