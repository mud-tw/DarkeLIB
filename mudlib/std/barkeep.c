//	/std/barkeep.c
//	from the Nightmare mudlib
//	an inheritable vendor of food and drink
//	created by Descartes of Borg October 1992

#include <std.h>

inherit MONSTER;

string *menu_items;

mapping menu;

string currency;

void set_menu(string *item_names, string *types, int *strengths);
void set_my_mess(string *msg);
void set_your_mess(string *msg);
void set_empty_container(string *empty);
void set_menu_short(string *str);
void set_menu_long(string *str);
void set_currency(string str);
int price(object tp, string strength);
int convert(mixed cost);
string *query_menu();
nomask void die();


void init() {
    ::init();
    add_action("buy", "buy");
    add_action("buy", "order");
}

void set_menu(string *item_names, string *types, int *strengths) {
    int i;

    menu_items = item_names;
    if(!menu) menu = ([]);
    for(i=0; i<sizeof(menu_items); i++) {
      menu[menu_items[i]] = ([ "type": types[i], "strength": strengths[i] ]);
    }
}

void set_my_mess(string *msg) {
    int i;

    for(i=0; i<sizeof(menu_items); i++) {
    	menu[menu_items[i]]["my message"] = msg[i];
    }
}

void set_your_mess(string *msg) {
    int i;

    for(i=0; i<sizeof(menu_items); i++) {
      menu[menu_items[i]]["your message"] = msg[i];
    }
}

void set_empty_container(string *container) {
    int i;

    for(i=0; i<sizeof(menu_items); i++) {
      menu[menu_items[i]]["empty container"] = container[i];
    }
}

void set_menu_short(string *str) {
    int i;

    for(i=0; i<sizeof(menu_items); i++) {
      menu[menu_items[i]]["short"] = str[i];
    }
}

void set_menu_long(string *str) {
    int i;

    for(i=0; i<sizeof(menu_items); i++) {
      menu[menu_items[i]]["long"] = str[i];
    }
}

void set_currency(string str) {
    currency = str;
}

int price(object tp, int strength) {
    int cost;
    float curr;

    curr = 0.08*to_float(strength) + pow(to_float(strength)/5.0, 1.3)*0.24;
    if(curr < 0.1) curr = 0.1;
    cost = convert(curr);
    if(!tp) return cost;
    if((int)tp->query_money(currency) < cost) return 0;
    tp->add_money(currency, -cost);

    return cost;
}

int convert(mixed x) {
    if(!x) return 0;
    if(intp(x)) x = to_float(x);
    else return 1 + to_int(currency_rate(currency)*x);
}

int buy(string str) {
    int i, cost;
    object ob;

    if(!str) {
        notify_fail(query_cap_name()+" says: What is it you would like?\n");
        return 0;
    }
    str = lower_case(str);
    if(member_array(str, menu_items) == -1) {
        notify_fail(query_cap_name()+" says: I don't serve that.\n");
        return 0;
    }
    if(!(cost = price(this_player(), menu[str]["strength"]))) {
        write(query_cap_name()+" says: You do not have enough "+currency+" for that!\n");
        say(query_cap_name()+" turns away "+this_player()->query_cap_name()+" for lack of money.\n", this_player());
        return 1;
    }
    write("You pay "+cost+" "+currency+" coins for a "+str+".\n");
    say(query_cap_name()+" collects some "+currency +" from "+this_player()->query_cap_name()+".\n", this_player());
    if(menu[str]["type"] == "food") {
        ob = new("std/food");
        ob->set_name(str);
        ob->set_id( ({str, "food" }) );
    }
    else if(menu[str]["type"] == "dine_in") {
        if(this_player()->query_stuffed() > 300) {
            write("You are far to full of food to be allowed to continue eating here....");
            say(this_player()->query_cap_name()+" is far too bloated to be allowed to continue eating here.");
            return 1;
        }
        this_player()->add_stuffed(menu[str]["strength"]);
        if(menu[str]["my message"])
            write(menu[str]["my message"]);
        if(menu[str]["your message"])
            say(this_player()->query_cap_name()+" "+menu[str]["your message"]);

        return 1;
    }
    else if(menu[str]["type"] == "drink_in") {

        if(this_player()->query_intox() > 300) {
            write("You are far to intoxicated to be allowed to continue drinking here....");
            say(this_player()->query_cap_name()+" is far too intoxicated to be allowed to continue drinking here.");
            return 1;
        }
        this_player()->add_intox(menu[str]["strength"]);
        this_player()->add_quenched(menu[str]["strength"]);

        if(menu[str]["my message"])
            write(menu[str]["my message"]);
        if(menu[str]["your message"])
            say(this_player()->query_cap_name()+" "+menu[str]["your message"]);

        return 1;

    } else {
        ob = new("std/drink");
        ob->set_name(str);
        ob->set_type(menu[str]["type"]);
        ob->set_id( ({ str, "drink" }) );
    }
    ob->set_strength(menu[str]["strength"]);
    ob->set_weight(to_int(2.3*pow(to_float(menu[str]["strength"]), 0.5)));
    i = menu[str]["strength"];
    ob->set_value( 1 );
    ob->set_destroy();
    if(menu[str]["short"]) ob->set_short(menu[str]["short"]);
    else ob->set_short(capitalize(str));
    if(menu[str]["long"]) ob->set_long(menu[str]["long"]);
    else ob->set_long(capitalize(str) + " from "+(string)environment(this_object())->query_short()+".\n");
    if(menu[str]["empty container"]) ob->set_empty_name(menu[str]["empty container"]);
    if(menu[str]["my message"]) ob->set_my_mess(menu[str]["my message"]);
    if(menu[str]["your message"]) ob->set_your_mess(menu[str]["your message"]);
    if(ob->move(this_player())) {
        write("You cannot carry it!\nYou drop a "+str+".\n");
        say(this_player()->query_cap_name()+" drops a "+str+".\n", this_player());
        ob->move(environment(this_player()));
    }

    return 1;
}

int get_price(string str) {
    if(!menu || !menu[str]) return 0;
    return price(0, menu[str]["strength"]);
}

string *query_menu() { return menu_items; }

nomask void die()
{
    int i;
    string *currs;

    currs = query_currencies();

    for(i=0;i < sizeof(currs); i++) {
	    add_money(currs[i], -query_money(currs[i]));
    }

    ::die();
}
