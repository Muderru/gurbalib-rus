#include "../domain.h"

inherit "/std/light";

void setup(void) {
   set_id("факел");
   set_short("Факел");
   set_long("На грязную палку намотана промасленная тряпка, " +
   "которую можно поджечь.");
   set_obj_i_name("факел");
   set_obj_r_name("факела");
   set_obj_d_name("факелу");
   set_obj_v_name("факел");
   set_obj_t_name("факелом");
   set_obj_p_name("факеле");
   set_obj_gender("male");
   set_gettable(1);

   set_value(1);
   set_weight(10);
   set_fuel(1000);
}

