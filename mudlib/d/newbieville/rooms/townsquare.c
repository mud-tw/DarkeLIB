#include "../newbieville.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();

    set_property("light", 3);
    set_property("indoors", 0);
    set("short", "城鎮廣場 Town Square.");
    set("long",
        "這裡是位於紐比維爾(Newbieville)中心點的城鎮廣場(Town Square), 四面八方的道路貫穿於此並各自延伸至城鎮的盡頭. 座落在前方不遠處的大城堡(Castle)應該就是當地領主順風爵士(Lord Tailwind)的住所. "
        // "This is the town square of Newbieville. In every direction, roads branch out to the ends of town. In front of you is a large castle, presumably that of Lord Tailwind."
    );
    add_exit(ROOMS+"castle", "castle");
    add_exit(ROOMS+"lightway", "east");
    add_exit(ROOMS+"shadowroad", "west");
    add_exit(ROOMS+"majestyave", "north");
    add_exit(ROOMS+"commonstreet", "south");
}
