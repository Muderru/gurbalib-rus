#include "../domain.h"

inherit "/std/object";

void setup(void) {
   set_id("букет", "цветы");
   add_id("розы", "алые");
   set_long("Прекрасный букет алых роз.");
   set_obj_i_name("букет роз");
   set_obj_r_name("букета роз");
   set_obj_d_name("букету роз");
   set_obj_v_name("букет роз");
   set_obj_t_name("букетом роз");
   set_obj_p_name("букете роз");
   set_obj_gender("male");
   set_gettable(1);
   set_value(10);
   set_weight(1);
}

string query_short(void) {
   if (this_object()->query_environment() && 
      (this_object()->query_environment()->is_living())) {
      return "Букет роз";
   }
   return "Кто-то оставил здесь букет роз.";
} 

