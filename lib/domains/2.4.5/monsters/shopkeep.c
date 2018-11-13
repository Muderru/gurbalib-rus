#include "../domain.h"

inherit "/std/vendor";

void setup(void) {
   set_name("торговец");
   add_ids("хозяин", "свилл", "хозяин магазина");
   set_gender("male");
   set_short("Торговец Свилл");
   set_long("Он - суровый громадный человек.");
   set_r_name("торговца");
   set_d_name("торговцу");
   set_v_name("торговца");
   set_t_name("торговцем");
   set_p_name("торговце");
   set_race("human");
   set_level(15);

   set_restock_delay(7200);
   set_will_buy(1);

   add_item(DIR + "/obj/torch", 8);
}
