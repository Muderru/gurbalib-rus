#include "../domain.h"

inherit "/std/armor";

void setup(void) {
   set_id("корона");
   add_ids("маленькая", "железная");
   set_short("Маленькая железная корона");
   set_long("Это недорогое украшение выглядит очень стильно.");
   set_obj_i_name("корона");
   set_obj_r_name("короны");
   set_obj_d_name("короне");
   set_obj_v_name("корону");
   set_obj_t_name("короной");
   set_obj_p_name("короне");
   set_obj_gender("female");
   set_gettable(1);
   set_slot("head");
   
   if (this_player()->query_gender() == "male") {
      set_wear_message("$N водрузил " + this_object()->query_obj_v_name() + " на голову.");
      set_remove_message("$N снял " + this_object()->query_obj_v_name() + ".");
   } else if (this_player()->query_gender() == "female") {
      set_wear_message("$N водрузила " + this_object()->query_obj_v_name() + " на голову.");
      set_remove_message("$N сняла " + this_object()->query_obj_v_name() + ".");
   } else {
      set_wear_message("$N водрузило " + this_object()->query_obj_v_name() + " на голову.");
      set_remove_message("$N сняло " + this_object()->query_obj_v_name() + ".");
   }
   
   set_ac(1);
   set_size(1);
   set_value(30);
   set_weight(2);
}
