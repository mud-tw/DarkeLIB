// Wizard:  Khojem
// Nutnux's Quest
// nutnux_quest_ob.c

inherit "std/quest_ob";

void create() {
    set_name("Nutnux's Quest");
    set_id( ({ "Nutnux's Quest", "quest_object" }) );
    set_short("A quest for Nutnux");
    set_long(
    "Nutnux is a fighter wandering in the Wastelands of Bir'Barrutt in "+
    "search of his much valued sash.  Help by returning his sash and he "+
    "will be a happy fighter once again.  He will also reward you, too.\n"+
    "Quest rating: Middle Level+ Only\n"
    );
    set_quest_points(25);
}
