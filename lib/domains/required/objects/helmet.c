#include "../domain.h"

inherit "/std/armor";

void setup(void) {
  
   set_id("шлем", "ржавый", "маленький");
   set_short("Маленький ржавый шлем");
   set_long("Вы видите маленький ржавый шлем, видавший лучшие дни. " +
      "Использовать его по назначению можно только от отчаяния.");
   set_obj_i_name("маленький ржавый шлем");
   set_obj_r_name("маленького ржавого шлема");
   set_obj_d_name("маленькому ржавому шлему");
   set_obj_v_name("маленький ржавый шлем");
   set_obj_t_name("маленьким ржавым шлемом");
   set_obj_p_name("маленьком ржавом шлеме");
   set_obj_gender("male");
   set_ac(1);
   set_slot("head");
   set_value(20);
   set_size(3);
   set_weight(1);
}
