inherit "/std/vault_locker_room.c";

void create()
{
    ::create();
    set("long", "巫師的工作室. ");

    // set_exits( ({ "/d/newbieville/rooms/townsquare"}), ({ "newbie" }) );
    add_exit("/d/newbieville/rooms/townsquare", "newbie");
}

void reset()
{
    ::reset();
}
