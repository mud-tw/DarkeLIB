//    A virtual server for forged weapons.
//    The file is of the format: "<weapon-name>_<qual>.weapon"
//    Weapon types are parsed from a text file /d/damned/data/weapon_types
//
//    DarkeLIB 0.1
//    -Diewarzau 8/14/95

#include <std.h>
#include "/d/damned/virtual/virtual_table.h"

inherit "/std/virtual/compile";
inherit WEAPON;

void virtual_setup(string arg);

void create() {
  seteuid(getuid(this_object()));
  ::create();
  return;
}

void virtual_setup(string arg) {
  object db;
  string type;
  class v_table this_weapon;
  int max, qual, i;

  if(sscanf(arg, "%s_%d", type, qual) != 2) {
    error("Error in virtual weapon file format.\n");
    /* An error here indicates failure to include quality */
    return;
  }
  set_name(replace_string(type, "-", " "));
  set("id", ({ query_name() }) );
  set_quality(qual);
  seteuid(getuid());
  db = load_object("/d/damned/data/weapon_db");
  this_weapon = (class v_table)db->get_table(type);
  if(!this_weapon) {
    error("Virtual weapon type not found: \""+type+"\"\n");
    return;
  }
  max = sizeof(this_weapon->funcs);
  for(i=0;i<max;i++) {
    if(this_weapon->funcs[i] == "set_value" &&
      sizeof(this_weapon->args[i])) {
      if(intp(this_weapon->args[i][0])) {
        this_object()->set_value(
        to_int(pow(1.6, to_float(qual-2)) * to_float(this_weapon->args[i][0])));
        continue;
      }
    }
    else if(this_weapon->funcs[i] == "set_float_value" &&
      sizeof(this_weapon->args[i])) {
      if(floatp(this_weapon->args[i][0])) {
        this_object()->set_float_value(this_weapon->
          args[i][0] * pow(1.6, to_float(qual-2)));
        continue;
      }
    }
    switch(sizeof(this_weapon->args[i])) {
    case 0:
    default:
      call_other(this_object(), this_weapon->funcs[i]);
      break;
    case 1:
      call_other(this_object(), this_weapon->funcs[i],
        this_weapon->args[i][0]);
      break;
    case 2:
      call_other(this_object(), this_weapon->funcs[i],
        this_weapon->args[i][0],
        this_weapon->args[i][1]);
      break;
    case 3:
      call_other(this_object(), this_weapon->funcs[i],
        this_weapon->args[i][0],
        this_weapon->args[i][1],
        this_weapon->args[i][2]);
      break;
    case 4:
      call_other(this_object(), this_weapon->funcs[i],
        this_weapon->args[i][0],
        this_weapon->args[i][1],
        this_weapon->args[i][2],
        this_weapon->args[i][3]);
      break;
    }
  }
  return;
}

