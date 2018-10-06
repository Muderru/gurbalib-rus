#include "../domain.h"

inherit "/std/armor";

void setup(void) {
   set_id("шапка", "огромная");
   set_adj("большая", "огромная");
   set_short("Огромная шапка");
   set_long("Она на несколько размеров больше, чем вам нужно. И еще она съезжает на глаза.");
   set_obj_i_name("огромная шапка");
   set_obj_r_name("огромной шапки");
   set_obj_d_name("огромной шапке");
   set_obj_v_name("огромную шапку");
   set_obj_t_name("огромной шапкой");
   set_obj_p_name("огромной шапке");
   set_obj_gender("female");   
   set_gettable(1);
   set_slot("head");
/*   
   set_wear_message("$N $vput $o on $p head.");
   set_remove_message("$N $vtake off $o.");
*/   
   set_value(20);
   set_weight(3);
   set_size(2);
}
