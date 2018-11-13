#include "../domain.h"

inherit "/std/object";

void setup(void) {
   set_id("посох");
   add_ids("золотой", "золотой посох");
   set_short("Золотой посох");
   set_long("Этот посох целиком сделан из золота. Он тяжелый, дорогой, но " +
   "абсолютно бесполезен в бою.");
   set_obj_i_name("золотой посох");
   set_obj_r_name("золотого посоха");
   set_obj_d_name("золотому посоху");
   set_obj_v_name("золотой посох");
   set_obj_t_name("золотым посохом");
   set_obj_p_name("золотом посохе");
   set_obj_gender("male");
   set_gettable(1);

   set_value(300);
   set_weight(10);
}
