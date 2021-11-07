#include "../newbieville.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();

    set_property("light", 3);
    set_property("indoors", 0);
    set("short", "威嚴大道 Majesty Avenue");
    set("long",
        "你走在威嚴大道(Majesty Avenue)上, 這是一條從城鎮廣場往北的主要道路. 在你的西邊的建築物是被譽為世界上最棒之一的酒吧, 東邊是一家盔甲店, 繼續往北走會到達北城門. "
        // "You are walking along Majesty Avenue, which goes north from the town square. "
        // "To your west is a bar, which is reputed to be one of the finest in the land. "
        // "East is an armor shop, and north are gates to the town."
    );
    add_exit(ROOMS+"bar", "west");
    add_exit(ROOMS+"armorshop", "east");
    add_exit(ROOMS+"townsquare", "south");
    add_exit(ROOMS+"ngates", "north");
}
