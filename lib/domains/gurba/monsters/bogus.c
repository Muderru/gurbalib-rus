#include "../domain.h"

inherit "/std/vendor";

void setup(void) {
   set_name("Богус");
   set_gender("male");
   add_id("торговец", "владелец", "богус");
   set_short("Богус, владелец магазина");
   set_long("Он страдает ожирением, а также алчностью.");
   set_r_name("Богуса");
   set_d_name("Богусу");
   set_v_name("Богуса");
   set_t_name("Богусом");
   set_p_name("Богусе");
   set_race("human");
   set_level(14);

   set_restock_delay(7200);

   add_item(DIR + "/objects/rock", 9);
   add_item(DIR + "/objects/boots", 5);
   add_item(DIR + "/objects/gloves", 6);
   add_item(DIR + "/objects/hat", 3);
   add_item(DIR + "/objects/jacket", 2);
   add_item(DIR + "/objects/tshirt", 1);
   add_item(DIR + "/objects/sword", 8);
}
