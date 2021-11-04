//  Wizard:  Khojem
//  Roulette Wheel
//  roulette_wheel.c
 
#include <std.h>

inherit OBJECT;

void init() {
	::init();
	add_action("rollim","play");
	add_action("read_plaque","read");
	add_action("read_plaque","look");
}
 
void create() {
  ::create();
    set_name("roulette table");
    set_id( ({ "roulette", "table", "roulette table" }) );
    set_short("a roulette table");
    set_long("A large roulette table with a well-worn felt tabletop.  Centered on "+
      "the table is a large dish-shaped wheel.  The wheel has numbers ranging from "+
      "1 to 36.  The numbers are set on alternating black and red color square "+
      "tiles.  A brass plaque can be seen to describe the rules of play.\n"
    );
    set_weight(10000);
    set_value(0);
}

int read_plaque(string str){
  if(str!="plaque") return 0;
  write("The brass plaque reads:  All wagers are 10 gold coins.\n\n"+
    "PLAY COLOR  red/black      Payoff:   20 gold coins\n"+
    "PLAY NUMBER number         Payoff:  360 gold coins\n\n"+
    "For example:\n"+
    "      play color  red\n"+
    "      play color  black\n"+
    "      play number 7\n"
  );
  say(this_player()->query_cap_name()+" looks over brass plaque.\n");
  return 1;
}

int rollim(string str){
 string token1,token2,color;
 int    do_play,spin,div,number;
 do_play=0;
 if(sscanf(str,"%s %s", token1, token2) == 2) {
   if((token1="color") && (token2=="black" || token2=="red"))
     do_play=1;
   else if((token1="number") &&  
       (token2=="1"  || token2=="2"  || token2=="3"  || token2=="4"  ||
        token2=="5"  || token2=="6"  || token2=="7"  || token2=="8"  ||
        token2=="9"  || token2=="10" || token2=="11" || token2=="12" ||
        token2=="13" || token2=="14" || token2=="15" || token2=="16" ||
        token2=="17" || token2=="18" || token2=="19" || token2=="20" ||
        token2=="21" || token2=="22" || token2=="23" || token2=="24" ||
        token2=="25" || token2=="26" || token2=="27" || token2=="28" ||
        token2=="29" || token2=="30" || token2=="31" || token2=="32" ||
        token2=="33" || token2=="34" || token2=="35" || token2=="36")) {
        do_play=2;
        sscanf(str,"%s %d", token1, number);
      }
 }
 if(do_play==0) {
   write("Huh?  Read the plaque and figure out the rules of play!");
   return 1; 
 }    
 if((int)this_player()->query_money("gold") < 10) {
   write("You search your pockets... but can't find the 10 gold "+
     "coins needed to play.");
   return 1;
 }
 say(this_player()->query_cap_name()+" plays the roulette wheel.");
 this_player()->add_money("gold", -10);
 spin=random(36)+1;
 div=(spin/2)*2;
 div=spin-div;
 if(div) 
   color="black";
 else 
   color="red";
 write("     The wheel spins the little ball goes round and round...\n"+
       "     Plink...  plink....   plink.....   "+spin+" "+color+"\n");
 if((do_play==1) && (color==token2)){
   write("     YOU WIN 20 GOLD COINS!");
   this_player()->add_money("gold", 20);
   say(this_player()->query_cap_name()+" just won.");
   return 1;
 }
 else if((do_play==2) && (number==spin)){
   write("     YOU WIN 360 GOLD COINS!");
   this_player()->add_money("gold", 360);
   say(this_player()->query_cap_name()+" just won big!");
   return 1;
 }
 write("     Sorry, you lose.");
 say(this_player()->query_cap_name()+ " just lost.");
 return 1;
}
