//      Wizard:  Khojem
//      glowstick
//      glowstick.c

 
#include <std.h>

inherit OBJECT;
 
int lit, fuel, light_time;
object shadow;

void create() {
  ::create();
    set_name("glowstick");
    set_id( ({ "glowstick" }) );
    set_short("a glowstick");
    set_long("A short glowstick.\n");
    set_weight(60);
    set_float_value(0.1);
    fuel = 2000;
    lit = 0;
    shadow = 0;
    set_property("no save", 1);
}
 

void init() {
    add_action("extinguish", "douse");
    add_action("light","light");
    add_action("extinguish","extinguish");
}
 
int light(string str) {
    if(effective_light(this_player()) < -2) {
	notify_fail("It is too dark.\n");
	return 0;
    }
    if(!str || present(str, this_player()) != this_object()) {
        notify_fail("Light what?\n");
        return 0;
    }
    if(!fuel) {
        notify_fail("The glowstick is out of fuel.\n");
        return 0;
    }
    if(lit) {
        notify_fail("It is already lit!\n");
        return 0;
    }
    write ("You light the glowstick.\n");
    seteuid(getuid());
    say(this_player()->query_cap_name()+" lights a glowstick.\n",
this_player());
    shadow = new("/std/spells/shadows/light_shad");
    shadow->set_light(2);
    shadow->start_shadow(environment());
    delayed_call("go_dark", fuel);
    light_time = time();
    lit = 1;
    return 1;
}
 
int extinguish(string str) {
    if(!str || present(str, this_player()) != this_object()) {
        notify_fail("Extinguish what?\n");
        return 0;
    }
    if(!lit) {
        notify_fail("The glowstick is not lit!\n");
        return 0;
    }
    write("You extinguish the glowstick.\n");
    say(this_player()->query_cap_name()+" extinguishes a glowstick.\n",
        this_player());
        fuel -= (light_time - time());
    if(shadow) shadow->external_destruct(shadow);
    remove_delayed_call("go_dark");
    lit = 0;
    return 1;
}
 
void go_dark() {
    if(shadow) shadow->external_destruct(shadow);
    fuel = 0;
    if(living(environment(this_object())))
	tell_object(environment(this_object()), "Your glowstick goes dark.\n");
    set_short(::query_short()+" (out of fuel)");
    set_long("The glowstick has exhuasted its fuel.\n");
    set_destroy();
    set_value(10);
    lit = 0;
}
 
string query_short() {
    string str;
 
    str = ::query_short();
    if(lit) str = str+ " (lit - it burns with a dull blue light)";
    return str;
}
 
int move(mixed dest) {
    int x;
 
    if(lit && shadow)
      shadow->external_destruct(shadow);
    x = ::move(dest);
    if(lit) {
      seteuid(getuid());
      shadow = new("/std/spells/shadows/light_shad");
      shadow->set_light(2);
      shadow->start_shadow(environment());
    }
    return x;
}

/*Plura 9302??*/
int query_lit() { return lit; }

/*Plura*/
int query_fuel() { return fuel; }

/* Valodin */
remove()
{
   if(lit && shadow)
      shadow->external_destruct(shadow);
   return ::remove();
}
