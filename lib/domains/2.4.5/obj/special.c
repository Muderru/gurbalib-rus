#include "../domain.h"

inherit "/std/object";

void setup(void) {
   set_id("вино");
   add_ids("домашнее", "специальное", "домашнее вино");
   set_short("Домашнее специальное");
   set_long("Вы видите бутылку превосходного вина. На его этикетке " +
   "написано 'Домашнее специальное'.");
   set_obj_i_name("домашнее вино");
   set_obj_r_name("домашнего вина");
   set_obj_d_name("домашнему вину");
   set_obj_v_name("домашнее вино");
   set_obj_t_name("домашним вином");
   set_obj_p_name("домашнем вине");
   set_obj_gender("neither");
   set_eatable(1);
   set_gettable(1);
   set_value(20);
   set_weight(2);
}

int do_eat(void) {
   int x;

   x = 10;
   write("По вашему телу растеклась теплая волна.");
   this_player()->query_environment()->tell_room(this_player(),
      this_player()->query_Name() + " пьет ароматное вино.\n");
   this_player()->increase_hp(x);
   this_object()->destruct();
}

int post_drop(void) {
   this_object()->query_environment()->tell_room(nil,
      "Вы слышите звон разбиваемого стекла, когда винная бутылка падает на землю.");
   this_object()->destruct();
}
