#include "../domain.h"

inherit "/std/armor";

void setup(void) {
   set_id("куртка");
   add_id("кожаная", "черная");
   set_short("Кожаная куртка");
   set_long("Такие куртки обычно носят %^RED%^плохие%^RESET%^ " +
      "парни.");
   set_obj_i_name("кожаная куртка");
   set_obj_r_name("кожаной куртки");
   set_obj_d_name("кожаной куртке");
   set_obj_v_name("кожаную куртку");
   set_obj_t_name("кожаной курткой");
   set_obj_p_name("кожаной куртке");
   set_obj_gender("female");
   set_gettable(1);
   set_slot("body");
/*    
   set_wear_message("$N $vput on $o. Man, $N $vare cool!");
   set_remove_message("$N $vtake off $o, and suddenly $vlook extremely dull.");
*/    
   set_ac(3);
   set_value(50);
   set_size(3);
   set_weight(7);
}
