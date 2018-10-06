#include "../domain.h"

inherit "/std/vendor";

void setup(void) {
   set_name("Фрида");
   set_gender("female");
   add_id("торговец", "цветочница", "фрида");
   set_short("Фрида, цветочница");
   set_long("Вы видите красивую девушку с длинной черной косой и " +
      "ромашкой за ухом.");
   set_r_name("Фриды");
   set_d_name("Фриде");
   set_v_name("Фриду");
   set_t_name("Фридой");
   set_p_name("Фриде");      
   set_race("human");
   set_level(15);

   set_restock_delay(7200);
   set_will_buy(1);

   add_item(DIR + "/objects/roses", 9);
}
