inherit "std/Object";

int rst;
void init() {
   ::init();
   add_action("q_fun", "q");
   rst = 1;
}

void create() {
   ::create();
   set_name("timer");
   set_id( ({"timer"}) );
   set_short("A reset timer.");
   set_long(
	"This is a reset timer. It times how much time passes "
	"between resets. And estimates the time of the next reset.");
   set_weight(0);
   set_value(0);
}
void reset() {
   ::reset();
   rst + rst + 1;
}
int q_fun() {
   write("h"+rst);
   return 1;
}
