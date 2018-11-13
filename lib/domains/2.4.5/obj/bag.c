#include "../domain.h"

inherit "/std/container";

void setup(void) {
   set_id("мешок");
   add_id("большой");
   set_short("Большой мешок");
   set_long("Похож на мешок, в котором обычно хранят муку.");
   set_obj_i_name("мешок");
   set_obj_r_name("мешка");
   set_obj_d_name("мешку");
   set_obj_v_name("мешок");
   set_obj_t_name("мешком");
   set_obj_p_name("мешке");
   set_obj_gender("male");
   set_weight(10);
   set_value(10);
   set_gettable(1);
}
