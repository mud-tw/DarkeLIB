//  Khojem
//  Sentry Gate Key
 
#include <std.h>

inherit OBJECT;
 
void create() {
  ::create();
    set_name("sentry gate key");
    set_id( ({ "sentry gate key", "key", "gate key" }) );
    set_short("sentry gate key");
    set_long("A stone key used by the city's sentries to lock the gate.\n");
    set_weight(10);
    set_value(10);
}
