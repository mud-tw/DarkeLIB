/* Duridian's Mirror */
 
#include <std.h>
inherit "/std/monster";
 
void create() {
   ::create();
   set_name("mirror");
   set("id", ({"mirror"}) );
   set_level(1);
   set("short", "Duridian's mirror");
   set("long",
"This mirror will reflect everything it sees, allowing coders to test "
"different output strings.  It's also good for vain players who like "
"to look at themselves."
   );
   set("race", "mirror");
   set_gender("neuter");
   set_exp(0);
   set_body_type("human");
}
 
void catch_tell(string str) {
   string a;
   if(sscanf(str, "%s", a) != 1) return;
   message("info", "%^BOLD%^Echo: %^RESET%^"+a, environment(this_object()), this_object());
}
