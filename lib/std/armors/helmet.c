inherit "/std/armor";

void setup(void) {
   set_id("шлем");
   set_short("Шлем");
   set_long("Самый обычный шлем, причем не высокого качества. " +
      "Вам лучше найти что-нибудь получше.");
   set_obj_i_name("шлем");
   set_obj_r_name("шлема");
   set_obj_d_name("шлему");
   set_obj_v_name("шлем");
   set_obj_t_name("шлемом");
   set_obj_p_name("шлеме");
   set_obj_gender("male");
   set_gettable(1);

   set_ac(1);

   set_slot("head");
   set_value(20);
   set_size(2);
   set_weight(1);
}
