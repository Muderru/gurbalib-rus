#include "../domain.h"

inherit "/std/weapon";

void setup(void) {
   set_id("меч");
   add_ids("огненный", "огненный меч");
   set_short("Огненный меч");
   set_long("Этот клинок раскален до красна. Это могучее оружие.");
   set_obj_i_name("огненный меч");
   set_obj_r_name("огненного меча");
   set_obj_d_name("огненному мечу");
   set_obj_v_name("огненный меч");
   set_obj_t_name("огненным мечом");
   set_obj_p_name("огненном мече");
   set_obj_gender("male");
   set_gettable(1);

   set_min_damage(5);
   set_max_damage(20);
   set_hit_bonus(5);

   set_weapon_skill("combat/sharp/large");

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
      set_weapon_action("опалил");
   } else if (this_player()->query_gender() == "female") {
      set_weapon_action("опалила");
   } else {
      set_weapon_action("опалило");
   }
   set_value(2000);
   set_size(4);
   set_weight(30);
}
