#include "../domain.h"

inherit "/std/object";

void setup(void) {
   set_id("банковский ключ");
   add_id("ключ");
   set_short("Банковский ключ");
   set_long("Это массивный железный ключ. Таким и убить можно");
   set_obj_i_name("банковский ключ");
   set_obj_r_name("банковского ключа");
   set_obj_d_name("банковскому ключу");
   set_obj_v_name("банковский ключ");
   set_obj_t_name("банковским ключом");
   set_obj_p_name("банковском ключе");
   set_obj_gender("male");
   set_gettable(1);

   set_value(8);
   set_weight(2);
}
