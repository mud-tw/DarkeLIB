//  Wizard:  Khojem
//  Earl of Vo'Sangor's Vault Key
//  vault_key.c

inherit "/std/armour";
 
void create() {
  ::create();
    set_name("earl's vault key");
    set_id( ({ "earl's vault key", "key", 
      "earl_vault_key", "vault key" }) );
    set_short("vault key");
    set_long("A large metal key that can be worn around the neck.\n");
    set_weight(5);
    set_value(0);
    set_type("visor");
    set_ac(1);
    set_limbs( ({ "head" }) );
}

