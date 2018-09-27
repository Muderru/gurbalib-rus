inherit "/std/armor";

void setup(void) {
   set_id("шлем");
   add_id("маленький", "ржавый");
   set_short("Маленький ржавый шлем");
   set_long("Похоже, что этот маленький ржавый шлем видал лучшие дни. " +
      "Надеть эту вещь можно только от полного отчаяния.");
   set_obj_i_name("маленький ржавый шлем");
   set_obj_r_name("маленького ржавого шлема");
   set_obj_d_name("маленькому ржавому шлему");
   set_obj_v_name("маленький ржавый шлем");
   set_obj_t_name("маленьким ржавым шлемом");
   set_obj_p_name("маленьком ржавом шлеме");
   set_obj_gender("male");
   set_gettable(1);

   set_ac(1);

   set_slot("head");
   set_value(20);
   set_size(1);
   set_weight(7);
}
