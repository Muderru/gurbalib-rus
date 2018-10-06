#include "../domain.h"

inherit "/std/object";

void setup(void) {
   set_id("валун");
   add_id("серый", "камень");
   set_short("Валун");
   set_long("Самый обычный серый камень.");
   set_obj_i_name("валун");
   set_obj_r_name("валуна");
   set_obj_d_name("валуну");
   set_obj_v_name("валун");
   set_obj_t_name("валуном");
   set_obj_p_name("валуне");
   set_obj_gender("male"); 
   set_gettable(1);
   set_weight(5);
}
