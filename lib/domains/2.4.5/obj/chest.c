#include "../domain.h"

inherit "/std/container";

void setup(void) {
   set_id("ящик");
   set_short("Ящик");
   set_long("Этот большой ящик сколочен из толстых дубовых досок.");
   set_obj_i_name("ящик");
   set_obj_r_name("ящика");
   set_obj_d_name("ящику");
   set_obj_v_name("ящик");
   set_obj_t_name("ящиком");
   set_obj_p_name("ящике");
   set_obj_gender("male");
   set_weight(10);
   set_internal_max_weight(1000);
   set_gettable(1);
   set_value(200);
}

