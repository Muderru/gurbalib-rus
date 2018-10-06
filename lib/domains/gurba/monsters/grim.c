#include "../domain.h"

inherit "/std/vendor";

void setup(void) {
   set_name("Грэм");
   set_gender("male");
   add_id("торговец", "оружейник", "грэм");
   set_short("Грэм - оружейник");
   set_long("Вы видите коренастого мускулистого гнома, черного " +
      "от копоти. Он много времени провел у кузнечного горна.");
   set_r_name("Грэма");
   set_d_name("Грэму");
   set_v_name("Грэма");
   set_t_name("Грэмом");
   set_p_name("Грэме");   
   set_race("dwarf");
   set_level(15);

   set_restock_delay(7200);

   add_item(DIR + "/objects/sword", 9);
   add_item(DIR + "/domains/required/objects/short_sword", 9);
}
