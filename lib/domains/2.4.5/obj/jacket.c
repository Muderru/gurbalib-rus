#include "../domain.h"

inherit "/std/armor";

void setup(void) {
   set_id("куртка");
   add_ids("поношенная", "кожаная", "поношенная куртка");
   set_short("Поношенная куртка");
   set_long("В таких крутых куртках любят разгуливать %^RED%^плохие%^RESET%^ " +
      "парни. На спине у куртки прикреплено множество заклепок, " +
      "образующих символ в виде перевернутой звезды.");
   set_obj_i_name("поношенная куртка");
   set_obj_r_name("поношенной куртки");
   set_obj_d_name("поношенной куртке");
   set_obj_v_name("поношенную куртку");
   set_obj_t_name("поношенной курткой");
   set_obj_p_name("поношенной куртке");
   set_obj_gender("female");
   set_gettable(1);
   set_slot("body");
   
   if (this_player()->query_gender() == "male") {
      set_wear_message("$N натянул " + this_object()->query_obj_v_name() + ", сложив пальцы веером.");
      set_remove_message("$N снял " + this_object()->query_obj_v_name() + ".");
   } else if (this_player()->query_gender() == "female") {
      set_wear_message("$N натянула " + this_object()->query_obj_v_name() + ", сложив пальцы веером.");
      set_remove_message("$N сняла " + this_object()->query_obj_v_name() + ".");
   } else {
      set_wear_message("$N натянуло " + this_object()->query_obj_v_name() + ", сложив пальцы веером.");
      set_remove_message("$N сняло " + this_object()->query_obj_v_name() + ".");
   }
   
   set_ac(3);
   set_value(50);
   set_size(3);
   set_weight(5);
}
