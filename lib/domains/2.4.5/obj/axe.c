#include "../domain.h"

inherit "/std/weapon";

void setup(void) {
   set_id("топорик");
   set_short("Топорик");
   set_long("Ржавый топорик на потертой деревянной рукоятке.");
   set_obj_i_name("топорик");
   set_obj_r_name("топорика");
   set_obj_d_name("топорику");
   set_obj_v_name("топорик");
   set_obj_t_name("топориком");
   set_obj_p_name("топорике");
   set_obj_gender("male");
   set_gettable(1);

   set_min_damage(1);
   set_max_damage(4);
   set_hit_bonus(0);

   set_weapon_skill("combat/sharp/small");

   set_wield_type("single");
   if (this_player()->query_gender() == "male") {
      set_wield_message("$N вооружился " + this_object()->query_obj_t_name() + ".");
      set_unwield_message("$N перестал использовать " + this_object()->query_obj_v_name() + ".");
   } else if (this_player()->query_gender() == "female") {
      set_wield_message("$N вооружилась " + this_object()->query_obj_t_name() + ".");
      set_unwield_message("$N перестала использовать " + this_object()->query_obj_v_name() + ".");
   } else {
      set_wield_message("$N вооружилось " + this_object()->query_obj_t_name() + ".");
      set_unwield_message("$N перестало использовать " + this_object()->query_obj_v_name() + ".");
   }
   
   if (this_player()->query_gender() == "male") {
      set_weapon_action("рубанул");
   } else if (this_player()->query_gender() == "female") {
      set_weapon_action("рубанула");
   } else {
      set_weapon_action("рубануло");
   }
   set_value(10);
   set_size(3);
   set_weight(2);
}
