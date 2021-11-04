//      Wizard:  Khojem
//      temple room template
//      template.c

#include <std.h>

inherit ROOM;

void init() {
    ::init();
}

void reset() {
    ::reset();
}

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set_property("night light",1);
    set("short", "template");
    set("day long",
      "It is day.\n"
   );
    set("night long",
      "It is night.\n"
    );
    set_items(([
     ({ "temple" , "room" }) :
        "It looks like a ruined temple.",
     ({ "floor" }) :
        "It is a floor." 
    ]));
    set_smell("default", "It smells");
    set_listen("default", "You hear?");
 }

