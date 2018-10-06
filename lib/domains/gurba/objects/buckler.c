#include "../domain.h"

inherit "/std/shield";

void setup(void) {
   set_id("щит");
   add_id("круглый щит", "круглый", "маленький");
   set_adj("маленький", "круглый");
   set_short("Маленький круглый щит");
   set_long("Самый обычный маленький круглый щит, называемый баклером.");
   set_obj_i_name("маленький круглый щит");
   set_obj_r_name("маленького круглого щита");
   set_obj_d_name("маленькому круглому щиту");
   set_obj_v_name("маленький круглый щит");
   set_obj_t_name("маленьким круглым щитом");
   set_obj_p_name("маленьком круглом щите");
   set_obj_gender("male"); 
   set_gettable(1);

   set_ac(1);

   set_wield_type("single");
/*   
   set_wield_message("$N $vequip $p $o.");
   set_unwield_message("$N $vremove $p $o.");
*/   
   set_value(20);
   set_size(1);
   set_weight(5);
}
