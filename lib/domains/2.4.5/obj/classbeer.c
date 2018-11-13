#include "../domain.h"

inherit "/std/object";

void setup(void) {
   set_id("пиво");
   add_id("первоклассное");
   set_short("Первоклассное пиво");
   set_long("Вы видите небольшую бутылку с желтой ароматной жидкостью.");
   set_obj_i_name("пиво");
   set_obj_r_name("пива");
   set_obj_d_name("пиву");
   set_obj_v_name("пиво");
   set_obj_t_name("пивом");
   set_obj_p_name("пиве");
   set_obj_gender("neither");
   set_eatable(1);
   set_gettable(1);
   set_value(12);
   set_weight(2);
}

int do_eat(void) {
   int x;

   x = random(5) + 1;
   write("Хорошо то как...");
   this_player()->query_environment()->tell_room(this_player(),
      this_player()->query_Name() + 
      " пьет пиво.\n");
   this_player()->increase_hp(x);
   this_object()->destruct();
}

int post_drop(void) {
   this_object()->query_environment()->tell_room(nil,
      "Вы слышите звон разбиваемого стекла, когда бутылка падает на землю.");
   this_object()->destruct();
}

