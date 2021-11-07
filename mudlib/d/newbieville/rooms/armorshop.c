//  Made by Tailwind for the BR Casino.
#include "../newbieville.h"
#include <std.h>

inherit "/std/vault";

void create()
{
    ::create();
    seteuid(getuid());

    set_property("light", 4);
    set_property("indoors", 1);
    set("short", "Armor Store");
    set("long", "這是由麥可(Michael)經營的精美盔甲和防具店, 他是一個聲名遠播的偉大盔甲大師. 事實上，他是如此偉大, 以至於關於他的盔甲製作能力的傳說傳遍了世界各地. 牆上掛著許多強大而昂貴的盔甲, 護手和手套放在一個櫃檯上. ");
    // set("long", "This is the Fine Armor and Protections Shop, run by Michael. Michael is a great armorer. In fact, he is so great that legends spread about his armormaking prowess as far as other dimensions. There are many powerful and expensive armors hanging on the walls, and gauntlets and gloves are in a counter top case.");
    add_exit(ROOMS+"majestyave", "west");
    add_exit(ROOMS+"lightway", "south");
    add_exit(ROOMS+"astores", "up");
    set_door(
        "iron door", ROOMS+"astores", "door",
        "newbieville armor store"
    );
    set_open("iron door", 0);
    set_locked("iron door", 1);
    set_lock_level("iron door", 22);
}

void reset() {
    ::reset();
    if (! present("michael")) {
        new(MON+"michael")->move(this_object());
    }
}
