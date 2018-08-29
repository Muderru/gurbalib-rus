#include "../domain.h"

inherit "/std/weapon";

void setup(void) {
   set_id("stick");
   add_id("branch");
   set_adj("short");
   set_long("A rough branch from a tree.");
   set_short("A stick");
   set_gettable(1);

   set_min_damage(1);
   set_max_damage(3);
   set_hit_bonus(1);

   set_weapon_skill("combat/blunt/small");

   set_wield_type("single");
   set_wield_message("$N $vgrab $o.");
   set_unwield_message("$N $vloosen $p $vgrip on $o, and $vput it away.");
   set_weapon_action("bash");
   set_value(1);
   set_size(6);
   set_weight(2);
}
