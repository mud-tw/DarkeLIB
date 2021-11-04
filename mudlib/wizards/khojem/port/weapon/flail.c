//  Khojem
//  flail
//  flail.c

inherit "/std/weapon";

create() {
  int qual;
    ::create();
    set_name("ball and chain");
    set_ac(3);
    set("id", ({ "ball", "iron ball and chain", "ball and chain", "chain", "flail" }));
    set("short", "iron ball and chain");
    set("long", "This weapon has a short metal rod with leather wrappings at one "+
      "end for a sure grip.  Attached to the other end of the rod is a short chain "+
      "with a spiked metal ball connected to the chain's end."
    );
    set_type("flail");
    qual = 5 + random(2);
    set_quality(qual);
    set_wc(17, "crushing");
    set_verb("smash");
    set_parry_bonus(-15);
    set_weight(185);
    set_value(90);
}

