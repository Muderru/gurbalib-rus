#include "../domain.h"

inherit "/std/vendor";

void setup(void) {
   set_name("трактирщик");
   add_ids("трактир", "том", "хозяин", "торговец");
   set_gender("male");
   set_short("Трактирщик Том");
   set_long("Вы видите большого полного мужчину, пышущего здоровьем.");
   set_r_name("трактирщика");
   set_d_name("трактирщику");
   set_v_name("трактирщика");
   set_t_name("трактирщиком");
   set_p_name("трактирщике");   
   set_race("human");
   set_level(15);

   set_restock_delay(7200);
   set_will_buy(1);

   add_item(DIR + "/obj/com_meal", 20);
   add_item(DIR + "/obj/mer_meal", 10);
   add_item(DIR + "/obj/ric_meal", 10);
   add_item(DIR + "/obj/mug", 10);
}
