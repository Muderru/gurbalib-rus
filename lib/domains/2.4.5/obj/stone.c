#include "../domain.h"

inherit "/std/object";

void setup(void) {

   set_id("камень");
   add_ids("черный", "черный камень");
   set_short("Черный камень");
   set_long("Это маленький черный камень. Возможно он представляет " +
   "какую-то ценность.");
   set_obj_i_name("черный камень");
   set_obj_r_name("черного камня");
   set_obj_d_name("черному камню");
   set_obj_v_name("черный камень");
   set_obj_t_name("черным камнем");
   set_obj_p_name("черном камне");
   set_obj_gender("male");
   set_gettable(1);
   set_value(60);
   set_weight(1);
}
