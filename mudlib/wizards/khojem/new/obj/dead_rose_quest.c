// Wizard:  Khojem
// Dead Rose Quest

inherit "std/quest_ob";

void create() {
    set_name("dead rose");
    set_id( ({ "dead rose", "quest_object" }) );
    set_short("The quest for a dead rose");
    set_long(
    "The Fir'nvillee hermit gnome is an aging hermit that lost her much valued "+
    "dead rose many years ago.  Aid the hermit and return her dead rose and "+
    "you will be greatly rewarded.\n"+
    "Quest rating: newbie\n"
    );
    set_quest_points(14);
}
