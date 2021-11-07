//	An example guildmaster for fighters.
//
//	DarkeLIB 0.1
//	Diewarzau 8/8/95

inherit "/std/guilds/npc_guildmaster";

//	He is set up identically to a monster.

void create()
{
    object ob;

    ::create();

    //  The one difference is the following line:
    set_join_room("/d/damned/guilds/join_rooms/thief_join");
    //  The above refers the guildmaster to the joining room, which
    //  handles all "book keeping"

    set("short", "Karin Wood, the Thief Guildmaster");
    set("long",
        "Karin is a brooding figure.  Through his thin eyes, he regards you cautiosly, fingering his "
        "dagger intermittently.");
    set_level(17);
    set_max_hp(5000);
    set_hp(5000);
    set_property("base mp regen", 45);
    set_property("base hp regen", 90);
    set_gender("male");
    set("race", "half-elf");
    set_body_type("half-elf");
    set_id(({"karin", "guildmaster", "thief", "thief guildmaster"}));
    //  NOTE:  It is important that, if you set_id, you include
    //  "guildmaster" as one of them.  If you do not set_id, he
    //  will still work.
    set_name("guildmaster");
    //  The name MUST be set to guildmaster if you want tell's to work.
    set_property("melee damage", (["crushing":50]));
    set_overall_ac(50);
    set_skill("conjuration", 65);
    set_spell_level("lightning bolt", 6);
    set_max_mp(2000);
    set_mp(2000);
    add_spell("lightning bolt", "$A");
    set_skill("melee", 60);
    set_skill("perception", 250);
    set_skill("dodge", 200);
    set_skill("parry", 150);
    set_skill("knife", 180);
    set_stats("strength", 150);
    set_stats("wisdom", 100);
    set_skill("attack", 160);
    set_stats("dexterity", 145);
    set_skill("steal", 200);
    set_languages(({"common", "middle-english", "yin", "treefolk", "catfolk", "elvish",
                    "dwarvish", "drow", "pix"}));
    set_property("ambidextry", 1);
    seteuid(getuid());

    ob = new ("/d/damned/guilds/thief/gm_dagger");
    ob->move(this_object());
    ob = new ("/d/damned/virtual/studded-leather-jacket.armour");
    ob->set_property("enchantment", 4);
    ob->move(this_object());
    ob = new ("/d/damned/virtual/leather-pants.armour");
    ob->move(this_object());

    force_me("wear pants");
    force_me("wear jacket");
    force_me("wield dagger in right hand");

    return;
}

int query_num_rounds() { return 2; }

void heart_beat()
{
    object *inv, pick;
    object ob;

    if (objectp(filter_array(all_inventory(environment()), "not_thief", this_object()))) {
        inv = filter_array(all_inventory(environment()), "not_thief", this_object());
        if (random(100) < 5 && inv && sizeof(inv))
        {
            pick = inv[random(sizeof(inv))];
            ob = new ("/std/skills/steal");
            ob->set_property("skill level", 95);
            ob->do_skill(this_object(), (string)pick->query_name());
        }
    }

    ::heart_beat();
    return;
}

int not_thief(object item)
{
    if (!living(item) || !objectp(item) || (string)item->query_class() == "thief")
        return 0;

    return 1;
}
