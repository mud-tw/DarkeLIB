//  Wizard:  Khojem
//  Chief Moped's Key
//  moped_key.c

inherit "/std/armour";
 
void create() {
  ::create();
    set_name("chief moped's key");
    set_id( ({ "chief moped's key", "key" }) );
    set_short("chief moped's key");
    set_long("A small metal key that can be worn around the neck.\n");
    set_weight(1);
    set_value(0);
    set_type("visor");
    set_ac(10);
    set_limbs( ({ "head" }) );
}

