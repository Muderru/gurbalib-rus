#include "../domain.h"

inherit "/std/weapon";

void setup(void) {
   set_id("молоток");
   set_adj("маленький");
   set_short("Маленький молоток");
   set_long("Самый обычный молоток. Он не годится для битвы, но с ним в " +
      "в руках вы не будете выглядеть бестолковым лентяем.");
   set_obj_i_name("маленький молоток");
   set_obj_r_name("маленького молотка");
   set_obj_d_name("маленькому молотку");
   set_obj_v_name("маленький молоток");
   set_obj_t_name("маленьким молотком");
   set_obj_p_name("маленьком молотке");
   set_obj_gender("male");
   set_gettable(1);

   set_min_damage(1);
   set_max_damage(1);
   set_hit_bonus(0);

   set_weapon_skill("combat/blunt/small");

   set_wield_type("single");
     if (this_player()->query_gender() == "male") {
      set_unwield_message("$N отложил в сторону маленький молоток.");
   } else if (this_player()->query_gender() == "female") {
      set_unwield_message("$N отложила в сторону маленький молоток.");
   } else {
      set_unwield_message("$N отложило в сторону маленький молоток.");
   }  
   set_wield_message("$N отложили в сторону маленький молоток.");
   set_weapon_action("bash");
   set_value(20);
   set_size(1);
   set_weight(6);
}
