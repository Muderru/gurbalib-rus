#include "../domain.h"

inherit "/std/vendor";

void setup(void) {
   set_name("Вилл");
   set_gender("male");
   add_id("торговец", "вилл", "владелец");
   set_short("Вилл, владелец магазина разнообразных товаров");
   set_long("Вилл - это уже не молодой мужчина с сединой в волосах. Видно, что " +
      "он повидал не мало на своем веку, а также что с ним надо держать ухо востро.");
   set_r_name("Вилла");
   set_d_name("Виллу");
   set_v_name("Вилла");
   set_t_name("Виллом");
   set_p_name("Вилле"); 
   set_race("human");
   set_level(15);

   set_restock_delay(7200);
   set_will_buy(1);

   add_item(DIR + "/obj/sweetroll", 12);
   add_item(DIR + "/obj/nails", 20);
   add_item(DIR + "/obj/hammer", 5);
   add_item(DIR + "/obj/lovers_locket", 10);
}

