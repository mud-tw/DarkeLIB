// /wizards/excelsior/rooms/shops/shoe_man

inherit "/std/npc_shop";

mapping people;
int given;

void reset() {
	::reset();
	if(!present("sword")) {
		new("/d/damned/virtual/long-sword_6.weapon")->move(this_object());
		command("wield sword in right hand");
	}
	given = 0;
}

void create() {
	::create();
	set_name("man");
	set("id",({"shoe man","man","shoe","man shoe","shopkeeper"}));
	set_level(17);
	set("short","shoe man");
	set("long","");
	set("race","human");
	set_gender("male");
	set_body_type("human");
	set_overall_ac( 18 );
	set_combat_chance(20);
	add_spell("cure critical wound","$(ME)");
	set_spell_level("cure critical wound",3);
	set_skill("prayer",70);
	set_skill("attack",100);
	set_skill("blade",95);
	set_skill("dodge",50);
	set_skill("parry",90);
	set_skill("melee",75);
	people = ([]);
	set_languages(({"pix","lamp","middle-english","common","vr'krr","serra",
		"pyrish","treefolk","hydran","thri'krien","ogryn","lithic"}));
	set("storage room","/wizards/excelsior/rooms/shops/shoe_storage");
	set("markup",10);
	set("no sell",1);
	reset();
}

void directed_message(object from,string what) {
	string str;
	object ob;
	if(what[0..3] == "pick") {
		message("info","Type 'pick up shoes'",from);
		return;
	}
	set_primary_lang((string)from->query_primary_lang());
	if(!query_primary_lang()) set_primary_lang("common");
	if(what == "talk") {
		command("say why, I've been in the shoe business for as long as "+
			"I can remember. My dad made shoes, my dad's dad made shoes, "+
			"and my dad's dad's dad was a trapeze artist. Actually, I've "+
			"always wanted to be a circus performer myself! I've even "+
			"started juggling, but I need one more juggling club. "+
			"Do you have a juggling club you could give me? Pleeeeeezzz?");
		return;
	}
	if(sscanf(what,"improve %s",str) == 1) {
		ob = present(str,from);
		if(!ob) {
			message("info","You don't have a "+str+".",from);
			return;
		}
		if((int)from->query_money("gold") < 100) {
			message("info","You do not have the 100 gold necassary to "+
				"improve that item",from);
			return;
		}
		if(!present(from)) {
			message("info","You have to be in the same room as the shoe man "+
				"to do this.",from);
			return;
		}
		if(!(int)ob->is_armour()) {
			message("info","The shoe man can only improve armour.",from);
			return;
		}
		if(people[(string)from->query_name()]) {
			message("info","The shoe man is already working on an item of yours.",
				from);
			return;
		}	
		if((string)ob->query_type() == "boots" || 
				(string)ob->query_type() == "shoes") {
			if((int)ob->query_property("improved") > 3) {
				command("say I don't think I can do any more with those "+
					"shoes. Sorry.");
				message("my_action","The shoe man shakes his head.",environment());
				return;
			}
			message("info","The shoe man takes your money and begins work on your
				shoes",from);
			command("say It will only take me a little bit.");
			message("info","The shoe man takes a pair of "+(string)from->
				query_cap_name()+" shoes and begins to work on them.",
				environment(),({from}));
			ob->move(this_object());
			if(!present(ob,this_object())) {
				message("info","The shoe man cannot carry those shoes.",environment());
				ob->move(environment());
				return;
			}
			from->add_money("gold",-100);
			call_out("work",15,ob,1,from);
			people[(string)from->query_name()] = ob;
			return;
		} else {
			command("say I'm sorry, I only work on armour worn on the feet.");
			message("my_action","The shoe man shakes his head.",environment());
			return;
		}
	}
	::directed_message(from,what);
}
			
void work(object ob,int times,object from) {
	string name;
	int i,ac;
	name = (string)from->query_name();
	if(times == (20 +(int)ob->query_property("improved")*5)) {
		command("tell "+name+" your shoes are done, you can now come "+
			"'pick up shoes' from me.");
		ac = (int)ob->query_ac();
		ac->set_ac(ac + 2 + random(4));
		i = (int)ob->query_property("improved");
		i++
;
		ob->set_property("improved",i);
		return;
	}
	times++;
	message("other_action","%^CYAN%^The shoe man works on a pair of shoes.",
		environment(),({this_object()}));
	call_out("work",14,ob,times,from);
}

void init() {
	::init();
	add_action("pick","pick");
	if(query_night()) {
		set("long","This is the apprentice to the shoe man. He mans the "+
			"shop at night in order to keep it open all day."+
			" Type "+
		"'say shopkeeper, help' for assistance. If you want to "+
		"just talk to him, tell him to 'talk'."+
		" If you want him to "+
		"improve a pair of shoes you already own, you can "+
		"'say shopkeeper, improve <shoes>' This costs a mere "+
		"100 gold. Shoes can be improved a maximum of 3 times.");
	} else {
		set("long","This is the shoe man. He deals in shoes."+
			" Type "+
		"'say shopkeeper, help' for assistance. If you want to "+
		"just talk to him, tell him to 'talk'."+
		" If you want him to "+
		"improve a pair of shoes you already own, you can "+
		"'say shopkeeper, improve <shoes>' This costs a mere "+
		"100 gold. Shoes can be improved a maximum of 3 times.");
	}
}

int pick(string str) {
	string name;
	int i;
	if(str != "up shoes") {
		notify_fail("You may want to 'pick up shoes'.\n");
		return 0;
	}
	set_primary_lang((string)this_player()->query_primary_lang());
	if(!query_primary_lang()) set_primary_lang("common");
	name = (string)this_player()->query_name();
	if(!name) return;
	if(!people[name]) {
		command("say I don't have a pair of your shoes.");
		return 1;
	}
	command("say thank you for your business, here are your shoes.");
	people[name]->move(this_player());
	if(!present(people[name],this_player()))
		people[name]->move(environment());
	i = (int)people[name]->query_property("improved");
	switch(i) {
		case 0:
			break;
		case 1..2:
			i = 3 - i;
			command("say I think I could improve those shoes "+i+" more times.");
			break;
		case 3..10000:
			command("say I think my work with those shoes is done.");
			break;
	}
}

void catch_tell(string str) {
	string who;
	object ob,ob2;
		if(sscanf(str,"%s gives you An %*s juggling club",who) == 2 || sscanf(str,"%s gives you A %*s juggling club",who) == 2) {
		ob = present(lower_case(who));
		if(!ob) return;
		ob2 = present("club",this_object());
		if(!ob2) return;
		set_primary_lang((string)ob->query_primary_lang());
		if(!query_primary_lang()) set_primary_lang("common");
		if(!ob2->is_right_club()) {
			command("say This is not a good club for juggling.");
			return;
		}
		command("say OH MY GOD! Jesus! This is just what I always wanted! "+
			"Oh nog you rock! Here, take this paint brush as a token of my "+
			"gratitude.");
		if(given > 5) {
			command("say well, I'd give you a paint brush but I seem to have given "+
				"my last one away!");
			message("other_action","The shoe man shrugs."
,
				environment(),({this_object()}));
			return;
		}
		message("other_action","The shoe man tosses a paint brush onto the ground."
,
			environment(),({this_object()}));
		new("/wizards/excelsior/obj/paint_brush")->move(environment());
		given++;
	}
}


string query_short() {
	if(!query_night()) {
		return ::query_short();
	} else {
		return "the apprentice shoe man";
	}
}
