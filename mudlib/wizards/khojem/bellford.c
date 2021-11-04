//  Khojem
//  Monster:  Mrs. Bellford

#include <std.h>

inherit MONSTER;

create() {
  ::create();
    set_name("bellford");
    set_id( ({ "bellford", "woman" }) );
    set_level(5);
    set_short("Mrs. Bellford");
    set_long("This is an older lady, perhaps in her late fifties. She is quite "+
      "overwieght and wears extravagant jewelry. From this and the rest of her "+
      "appearance, you gather that she is travelling somewhere but has "+
      "currently made a stop here and wait for the morrow to continue her "+
      "travels. She is very absorbed playing with her poodle currently "+
      "and does not even notice your intrusion."
      );
    set("race", "human");
    set_gender("female");
    set_body_type("human");
    set_stats("intelligence", 40);
    set_property("melee damage", ([ "crushing" : 0]));
    set_emotes(30,({
      "Mrs. Bellford says, 'Poopsie! Oh, Poopsie!' and slaps her poodle hard.",
      "Mrs. Bellford throws her poodle into the air but fails in catching him and
watches in dismay as he comes crashing down.",
      "Mrs. Bellford says: Oooooooh! My dear poopsie!",
    }),0);    
}
