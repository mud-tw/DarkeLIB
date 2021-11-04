// **** Code done by Zarlock ****

#include <std.h>

inherit OBJECT;
int uses;

void create() {
    ::create();

    set_name("ring");
    set_id( ({ "golden ring", "small golden ring", "a small golden ring" })
);
    set_short("A small golden ring");
    set_long(
        "A ring of solid gold. You sense it has magical properties, maybe "
        "you should try and rub it and see what happens."
    );
    set_weight(1);
    set_value(150);
    uses = 1;
}

void init() {
    add_action("do_rub", "rub");
}

int do_rub(string str) {
    object nerd;
    if(str != "ring") {
     notify_fail("Rub what?\n");
     return 0;
    }
    if(!uses) {
     write("You can only use this ring once.\n");
     return 1;
    }
    write("You rub the ring and feel strange. You vanish from sight!\n");
    say(this_player()->query_name()+ " rubs his ring and vanishes from "+
      "sight!\n");
    this_player()->set_invis(1);
    uses--;
    nerd = this_player();
    delayed_call("visible", 20,nerd);
    return 1;
}

void visible(object tp) {
    tp->set_invis(0);
    tell_object(tp,"The magic of the ring wears off.\n");
    return 0;
}
