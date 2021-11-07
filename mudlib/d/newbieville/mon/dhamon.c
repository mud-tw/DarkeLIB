//  Wizard:  Khojem
//  Barfir
//  barfir.c
//  Altered by Tailwind for Newbieville.

#include "../newbieville.h"
#include <std.h>

inherit BARKEEP;

create() {
    ::create();
   set_property("no bump", 1);
   set_name("dhamon");
   set_id( ({ "dhamon", "barkeep" }) );
   set_short( "酒吧老闆 達蒙(Dhamon)" );
   set_level(12);
   set_long("達蒙是個很受歡迎的年輕酒吧老闆, 總是把最好喝的酒推薦給客人. ");
   // set_long("Dhamon is a pleasant young man who only wants to serve you the finest alcohol available.");
   set_gender("male");
   set_alignment(122);
   set("race", "human");
   add_money("silver", random(500));
   set_body_type("human");
   set_currency("silver");
   set_menu(
        // ({ "甜莓酒", "精釀啤酒", "廉價啤酒" }),
        ({ "sweetberry wine", "fine brew", "cheap ale" }),
        ({ "alcoholic", "alcoholic", "alcoholic" }),
        ({ 15, 10, 5 })
    );

    set_my_mess( ({
        "The sweetberry wine goes smoothly down your throat.\n",
        "This fine brew is good stuff!\n",
        "You down some generic ale. Cheap stuff, but it works.\n"
    }) );

    set_your_mess( ({
        "looks like he's enjoying his wine.\n",
        "enjoys his fine brew.\n",
        "drinks some ale, and isn't impressed.\n"
    }) );

    set_menu_short( ({
        "Some sweetberry wine",
        "A fine brew",
        "A cheap ale"
    }) );

    set_menu_long( ({
        "Sweetberry wine, which is made from the finest sweetberries in all of Daybreak Ridge.\n",
        "Some fine brew, specially made by Jack.\n",
        "A cheap ale for those not so stout of heart.\n"
    }) );
}
