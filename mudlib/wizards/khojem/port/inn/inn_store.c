inherit "std/room";

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",1);
   set_property("storage room",1);
   set("short","Inn  storage");
   set("long","Ditto for the short!");
   set_exits( ([]) );
}
