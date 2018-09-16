#include "../domain.h"

inherit "/std/container";

void setup(void) {
   set_id("стол");
   set_adj("деревянный", "маленький");
   set_short("Маленький стол");
   set_long("Это небольшой деревянный стол с изогнутыми ножками.");
   set_obj_i_name("стол");
   set_obj_r_name("стола");
   set_obj_d_name("столу");
   set_obj_v_name("стол");
   set_obj_t_name("столом");
   set_obj_p_name("столе");
   set_obj_gender("male"); 

   set_objects(DIR + "/obj/potion");
}
