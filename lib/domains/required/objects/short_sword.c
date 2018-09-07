#include "../domain.h"

inherit "/std/weapon";

void setup(void) {
   set_combat_stats(1, 3, 0);
   set_id("меч", "короткий");
   set_short("Короткий меч");
   set_long("Это самый обычный короткий меч.");
   set_obj_i_name("короткий меч");
   set_obj_r_name("короткого меча");
   set_obj_d_name("короткому мечу");
   set_obj_v_name("короткий меч");
   set_obj_t_name("коротким мечом");
   set_obj_p_name("коротком мече");
   set_obj_gender("male");

   set_value(30);
   set_size(2);
   set_weight(2);
}

