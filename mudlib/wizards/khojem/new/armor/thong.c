//  Wizard:  Khojem
//  leather thong
//  thong.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("leather thong");
    set("id", ({ "thong", "leather thong" }) );
    set("short", "leather thong");
    set("long", "You wonder why anyone would bother to wear it!  "+
      "If you can't use your imagination of what a leather thong looks "+
      "like...  you live on another planet...");
    set_weight(5);
    set("value", 10);
    set_type("pants");
    set_limbs( ({ "left leg", "right leg" }) );
    set_ac(0);
    set_material("misc/soft leather");
}
