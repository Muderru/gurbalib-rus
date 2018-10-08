#include "../domain.h"

inherit "/std/object";

void setup(void) {
   set_id("дерево");
   set_short("Большое мертвое дерево");
   set_long("Это большое, но мертвое дерево.  Оно выглядит очень древним.  " +
      "Вы можете сломать одну из его веток и использовать ее в качестве оружия.");
   set_obj_i_name("дерево");
   set_obj_r_name("дерева");
   set_obj_d_name("дереву");
   set_obj_v_name("дерево");
   set_obj_t_name("деревом");
   set_obj_p_name("дереве");
   set_obj_gender("neuter");
}
