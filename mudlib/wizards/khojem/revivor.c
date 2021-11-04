inherit "std/Object";

void create() {
	::create();
	set_short("Excelsior's Quick revival tool");
	set_long("With this tool anyone can be rivived with an easy 'revive
<player>" +
"'. It is not to be sold or held by mortals.");
	set_value( 5000 );
	set_weight( 1 );
	set_name("revivor");
	set_id( ({"revivor","tool","rocking thing"}));
}

void init() {
	if ( interactive(environment(this_object())) ) {
	if( !wizardp(environment(this_object()))) this_object()->remove();
	}
        add_action("revive","revive");
	::init();
}

void revive(string str) {
	object who;
	who = find_player(str);
	if (!who) {
		write("You suck.");
		return 1;
	}
	if ( !who->query_ghost() ) {
		notify_fail("You really suck.");
		return 1;
	}
	if ( !wizardp( this_player() ) ) return 1;
	who->revive();
	who->set_hp(10);
	who->set_heart_beat(1);
	who->set_heal_rate(2);
	return 1;
}
