#include "../domain.h"

inherit "/std/shield";

void setup(void) {
   set_id("щит");
   add_id("круглый");
   set_short("Круглый щит");
   set_long("Круглый щит, вроде ничего необычного.");
   set_obj_i_name("круглый щит");
   set_obj_r_name("круглого щита");
   set_obj_d_name("круглому щиту");
   set_obj_v_name("круглый щит");
   set_obj_t_name("круглым щитом");
   set_obj_p_name("круглом щите");
   set_obj_gender("male");   
   set_gettable(1);

   set_ac(2);

   set_wield_type("single");
/*   
   set_wield_message("$N $vwield $p $o.");
   set_unwield_message("$N $vremove $p $o.");
*/ 
   set_value(1);
   set_size(6);
   set_weight(10);
}
