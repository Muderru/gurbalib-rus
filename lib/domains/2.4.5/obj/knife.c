#include "../domain.h"

inherit "/std/weapon";

void setup(void) {
   set_id("нож");
   set_short("Нож");
   set_long("Вы видите небольшой острый нож с удобной деревянной рукояткой.");
   set_obj_i_name("нож");
   set_obj_r_name("ножа");
   set_obj_d_name("ножу");
   set_obj_v_name("нож");
   set_obj_t_name("ножом");
   set_obj_p_name("ноже");
   set_obj_gender("male");
   set_gettable(1);

   set_min_damage(1);
   set_max_damage(3);
   set_hit_bonus(0);

   set_weapon_skill("combat/sharp/small");

   set_wield_type("single");
   
   if (this_player()->query_gender() == "male") {
      set_wield_message("$N взял в руку " + this_object()->query_obj_v_name() + ".");
      set_unwield_message("$N перестал использовать " + this_object()->query_obj_v_name() + ".");
   } else if (this_player()->query_gender() == "female") {
      set_wield_message("$N взяла в руку " + this_object()->query_obj_v_name() + ".");
      set_unwield_message("$N перестала использовать " + this_object()->query_obj_v_name() + ".");
   } else {
      set_wield_message("$N взяло в руку " + this_object()->query_obj_v_name() + ".");
      set_unwield_message("$N перестало использовать " + this_object()->query_obj_v_name() + ".");
   }
   
   if (this_player()->query_gender() == "male") {
      set_weapon_action("пырнул");
   } else if (this_player()->query_gender() == "female") {
      set_weapon_action("пырнула");
   } else {
      set_weapon_action("пырнуло");
   }
   
   set_value(8);
   set_size(6);
   set_weight(2);
}
