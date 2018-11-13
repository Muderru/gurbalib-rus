#include "../domain.h"

inherit "/std/object";

void setup(void) {
   set_id("еда");
   add_id("простая");
   set_short("Простая еда");
   set_long("Вы видите маленькую миску с куском хлеба, на который " +
      "что-то намазано. Воняет неприятно...");
   set_obj_i_name("простая еда");
   set_obj_r_name("простой еды");
   set_obj_d_name("простой еде");
   set_obj_v_name("простую еду");
   set_obj_t_name("простой едой");
   set_obj_p_name("простой еде");
   set_obj_gender("female");
   set_eatable(1);
   set_gettable(1);
   set_value(20);
   set_weight(2);
}

int do_eat(void) {
   int x;

   x = random(5) + 1;
   write("Вы съели миску простой еды. На запах - не очень, как и на вкус");
   this_player()->query_environment()->tell_room(this_player(),
      this_player()->query_Name() + 
      " съедает что-то несвежее и не приятно пахнущее.\n");
   this_player()->increase_hp(x);
   this_object()->destruct();
}
