#include "../domain.h"

inherit "/std/armor";

void setup(void) {
   set_id("перчатки");
   add_id("кожаные", "кожаные перчатки");
   set_adj("красные");
   set_short("Пара кожаных перчаток");
   set_long("Это самые обычные кожаные перчатки, выкрашенные в красный цвет.");
   set_obj_i_name("кожаные перчатки");
   set_obj_r_name("кожаных перчаток");
   set_obj_d_name("кожаным перчаткам");
   set_obj_v_name("кожаных перчатках");
   set_obj_t_name("кожаными перчатками");
   set_obj_p_name("кожаных перчатках");
   set_obj_gender("plural");   
   set_gettable(1);
   set_slot("hands");
/*   
   set_wear_message("$N $vwear $o.");
   set_remove_message("$N $vremove $o.");
*/   
   set_value(20);
   set_size(4);
   set_weight(5);
}
