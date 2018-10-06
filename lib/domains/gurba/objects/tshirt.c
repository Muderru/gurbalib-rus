#include "../domain.h"

inherit "/std/armor";

void setup(void) {
   set_id("рубаха", "цветная");
   set_short("Цветная рубаха");
   set_long("Самая обычная цветная рубаха. Очень безвкусная и " +
      "простая.");
   set_obj_i_name("цветная рубаха");
   set_obj_r_name("цветной рубахи");
   set_obj_d_name("цветной рубахе");
   set_obj_v_name("цветную рубаху");
   set_obj_t_name("цветной рубахой");
   set_obj_p_name("цветной рубахе");
   set_obj_gender("female");   
   set_gettable(1);
   set_slot("torso");
/*   
   set_wear_message("$N $vput on $o, and suddenly $vlook a lot better.");
   set_remove_message("$N $vtake off $o, and suddenly $vlook dull.");
*/    
   set_ac(1);
   set_value(20);
   set_size(1);
   set_weight(3);
}
