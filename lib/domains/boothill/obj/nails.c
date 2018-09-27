#include "../domain.h"

inherit "/std/object";

void setup(void) {
   set_id("гвозди");
   add_ids("коробка гвоздей", "коробка");
   set_adj("небольшая");
   set_short("Небольшая коробка гвоздей");
   set_long("Незаменимая вещь при строительстве и ремонте.");
   set_obj_i_name("коробка гвоздей");
   set_obj_r_name("коробки гвоздей");
   set_obj_d_name("коробке гвоздей");
   set_obj_v_name("коробку гвоздей");
   set_obj_t_name("коробкой гвоздей");
   set_obj_p_name("коробке гвоздей");
   set_obj_gender("female");
   set_gettable(1);
   set_weight(10);
   set_value(10);
}
