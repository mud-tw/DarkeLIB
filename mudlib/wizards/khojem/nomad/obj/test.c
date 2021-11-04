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
    set_weight(9000);
    set_value(0);
}

int read_plaque(string str){
  if(str!="plaque") return 0;
  write("The brass plaque reads:  All wagers are 10 gold coins.\n\n"+
    "PLAY red/black      Payoff:   20 gold coins\n"+
    "PLAY number         Payoff:  360 gold coins\n\n"+
    "For example:\n"+
    "      play color red\n"+
    "      play color black\n"+
    "      play number 7\n"
  );
  say(this_player()->query_cap_name()+" looks over brass plaque.\n");
  return 1;
}

int rollim(string str){
  string token,bet,color;
  int    color_bet,good_bet,div,spin,win;
  write(str);
  good_bet=0;
  win=0;
  if(sscanf(str, "%*scolor %s", bet) == 2) 
    color_bet=1;
  else if(sscanf(str, "%*snumber %s", bet) == 2)
      color_bet=0;
    else {
      write("You messed up the play!  Read the plaque and try, again.\n");
      return 1;
    }
  if(color_bet) {
    if(bet=="red" || bet=="black") good_bet=1;
  }
  if(!color_bet) {
    if(bet=="1" || bet=="2" || bet=="3" || bet=="4" || bet=="5" || bet=="6" ||
       bet=="7" || bet=="8" || bet=="9" || bet=="10" || bet=="11" || bet=="12" ||
       bet=="13" || bet=="14" || bet=="15" || bet=="16" || bet=="17" || bet=="18" ||
       bet=="19" || bet=="20" || bet=="21" || bet=="22" || bet=="23" || bet=="24" ||
       bet=="25" || bet=="26" || bet=="27" || bet=="28" || bet=="29" || bet=="30" ||
       bet=="31" || bet=="32" || bet=="33" || bet=="34" || bet=="35" || bet=="36")
      good_bet=1;
  }
  if(!good_bet) {
      write("You messed up the play!  Read the plaque and try, again.\n");
      return 1;
  }
  if((int)this_player()->query_money("gold") < 10) {
    write("You search your pockets... but can't find the 10 gold "+
      "coins needed to play.");
    return 1;
  }
  write("color_bet ="+color_bet+"  bet ="+bet);
  spin=random(37);
//  say(this_player()->query_cap_name()+" plays the roulette wheel.\n");
//  this_player()->add_money("gold", -10);
  spin=1;
  div=(spin/2)*2;
  div=spin-div;
  if(div) 
    color="black";
  else 
    color="red";
  write("     The wheel spins the little ball goes round and round...\n"+
    "     Plink...  plink....   plink.....   "+spin+" "+color+"\n"); 
  if(!color_bet) {
      if((spin==1) && (bet=="1")) win=1;
      if((spin==2) && (bet=="2")) win=1;
      if((spin==3) && (bet=="3")) win=1;
      if((spin==4) && (bet=="4")) win=1;
      if((spin==5) && (bet=="5")) win=1;
      if((spin==6) && (bet=="6")) win=1;
      if((spin==7) && (bet=="7")) win=1;
      if((spin==8) && (bet=="8")) win=1;
      if((spin==9) && (bet=="9")) win=1;
      if((spin==10) && (bet=="10")) win=1;
      if((spin==11) && (bet=="11")) win=1;
      if((spin==12) && (bet=="12")) win=1;
      if((spin==13) && (bet=="13")) win=1;
      if((spin==14) && (bet=="14")) win=1;
      if((spin==15) && (bet=="15")) win=1;
      if((spin==16) && (bet=="16")) win=1;
      if((spin==17) && (bet=="17")) win=1;
      if((spin==18) && (bet=="18")) win=1;
      if((spin==19) && (bet=="19")) win=1;
      if((spin==20) && (bet=="20")) win=1;
      if((spin==21) && (bet=="21")) win=1;
      if((spin==22) && (bet=="22")) win=1;
      if((spin==23) && (bet=="23")) win=1;
      if((spin==24) && (bet=="24")) win=1;
      if((spin==25) && (bet=="25")) win=1;
      if((spin==26) && (bet=="26")) win=1;
      if((spin==27) && (bet=="27")) win=1;
      if((spin==28) && (bet=="28")) win=1;
      if((spin==29) && (bet=="29")) win=1;
      if((spin==30) && (bet=="30")) win=1;
      if((spin==31) && (bet=="31")) win=1;
      if((spin==32) && (bet=="32")) win=1;
      if((spin==33) && (bet=="33")) win=1;
      if((spin==34) && (bet=="34")) win=1;
      if((spin==35) && (bet=="35")) win=1;
      if((spin==36) && (bet=="36")) win=1;
    }
    if(win) {
      write("     YOU WIN 360 GOLD COINS!\n");
      this_player()->add_money("gold", 360);
      say(this_player()->query_cap_name()+" just won big!");
      return 1;
    }
    else {
      write("     Sorry, you lose.\n");
      say(this_player()->query_cap_name()+ " just lost.");
      return 1;
    }
  }
}
