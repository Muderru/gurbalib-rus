#include "../domain.h"

inherit "/std/object";

void setup(void) {
   set_id("зелье", "маленькое", "красное");
   set_adj("small", "healing", "red");
   set_short("Маленькое красное зелье");
   set_long("Вы видите маленькую изящную бутылочку, заполненную мерцающей красной жидкостью. " +
      "На этикетке написано, что это зелье лечения.\n");
   set_obj_i_name("маленькое красное зелье");
   set_obj_r_name("маленького красного зелья");
   set_obj_d_name("маленькому красному зелью");
   set_obj_v_name("маленькое красное зелье");
   set_obj_t_name("маленьким красным зельем");
   set_obj_p_name("маленьком красном зелье");
   set_obj_gender("neuter"); 
   set_eatable(1);
   set_gettable(1);
   set_value(10);
   set_weight(2);
}

int do_eat(void) {
   int x;

   x = random(5) + 1;
   write("Вы выпили зелье и почувствовали разливающееся по телу целительное тепло.\n");
         if (this_player()->query_gender() == "male") {
            this_player()->query_environment()->tell_room(this_player(),
             this_player()->query_Name() + " выпил зелье лечения.\n");
       } else if (this_player()->query_gender() == "female") {
            this_player()->query_environment()->tell_room(this_player(),
             this_player()->query_Name() + " выпила зелье лечения.\n");
       } else {
            this_player()->query_environment()->tell_room(this_player(),
             this_player()->query_Name() + " выпило зелье лечения.\n");
       }
   this_player()->increase_hp(x);
   this_object()->destruct();
}
