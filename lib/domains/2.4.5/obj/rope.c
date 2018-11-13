#include "../domain.h"

inherit "/std/object";

string tied_to;
object tied_to_obj;

void setup(void) {
   set_id("веревка");
   add_ids("старая", "старая веревка");
   set_obj_i_name("старая веревка");
   set_obj_r_name("старой веревки");
   set_obj_d_name("старой веревке");
   set_obj_v_name("старую веревку");
   set_obj_t_name("старой веревкой");
   set_obj_p_name("старой веревке");
   set_obj_gender("female");
   set_gettable(1);
   set_value(15);
   set_weight(10);
   set_short("Старая веревка");
}

string query_long() {
   if (tied_to) {
      return "Вы видите старую веревку, привязанную к " + tied_to + ".";
   }
   return "Стара веревка, вроде ничего особенного.";
}

void set_tied(string str) {
   if (!str || (str == "")) {
      tied_to = "";
      set_short("Старая веревка");
   } else {
      tied_to = str;
      set_short("Старая веревка, привязанная к " + tied_to );
   }
}
