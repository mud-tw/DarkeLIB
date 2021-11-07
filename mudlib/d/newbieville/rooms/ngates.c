#include "../newbieville.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();

    set_property("light", 3);
    set_property("indoors", 0);
    set("short", "北門口 North Gates");
    set("long", "這裡是紐比維爾(Newbieville)的北城門, 往北是一片平原(plains), 往南穿過威嚴大道(Majesty Avenue)通往城鎮廣場(Town Square). ");
    // set("long", "These are the northern gates leading out from Newbieville. To the south is Majesty Avenue, which will take you to Town Square if you follow it.");
    add_exit(ROOMS+"majestyave", "south");
    add_exit("/d/damned/virtual/room_10_10.world", "plains");
}
