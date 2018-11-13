#include "../domain.h"

inherit "/std/armor";

void setup(void) {
   set_id("доспех");
   add_ids("кожаный", "кожаный доспех");
   set_short("Кожаный доспех");
   set_long("Простая, но достаточно надежная защита для тела.");
   set_obj_i_name("кожаный доспех");
   set_obj_r_name("кожаного доспеха");
   set_obj_d_name("кожаному доспеху");
   set_obj_v_name("кожаный доспех");
   set_obj_t_name("кожаным доспехом");
   set_obj_p_name("кожаном доспехе");
   set_obj_gender("male");
   set_gettable(1);
   set_slot("body");
   
   if (this_player()->query_gender() == "male") {
      set_wear_message("$N нахлобучил " + this_object()->query_obj_v_name() + " на тело.");
      set_remove_message("$N снял " + this_object()->query_obj_v_name() + ".");
   } else if (this_player()->query_gender() == "female") {
      set_wear_message("$N нахлобучила " + this_object()->query_obj_v_name() + " на тело.");
      set_remove_message("$N сняла " + this_object()->query_obj_v_name() + ".");
   } else {
      set_wear_message("$N нахлобучило " + this_object()->query_obj_v_name() + " на тело.");
      set_remove_message("$N сняло " + this_object()->query_obj_v_name() + ".");
   }
   
   set_ac(3);
   set_value(110);
   set_size(3);
   set_weight(10);
}
