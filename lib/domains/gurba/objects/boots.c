#include "../domain.h"

inherit "/std/armor";

void setup(void) {
   set_id("ботинки");
   add_id("отличные");
   set_adj("красные");
   set_short("Пара отличных ботинок");
   set_long("Похоже, что эти ботинки сделаны из отличной крокодильей кожи.");
   set_obj_i_name("отличные ботинки");
   set_obj_r_name("отличных ботинок");
   set_obj_d_name("отличным ботинкам");
   set_obj_v_name("отличные ботинки");
   set_obj_t_name("отличными ботинками");
   set_obj_p_name("отличных ботинках");
   set_obj_gender("plural");   
   set_gettable(1);
   set_slot("feet");
/*   
   set_wear_message("$N $vput on $o.");
   set_remove_message("$N $vtake off $o.");
*/  
   set_value(20);
   set_size(6);
   set_weight(6);
}
