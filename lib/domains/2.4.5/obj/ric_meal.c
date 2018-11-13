#include "../domain.h"

inherit "/std/object";

void setup(void) {
   set_id("еда");
   add_ids("дорогая", "дорогая еда");
   set_short("Дорогая еда");
   set_long("В небольшом горшочке вы видите изысканное блюдо, " +
      "приправленное ароматным соусом и тертым сыром.");
   set_obj_i_name("дорогая еда");
   set_obj_r_name("дорогой еды");
   set_obj_d_name("дорогой еде");
   set_obj_v_name("дорогую еду");
   set_obj_t_name("дорогой едой");
   set_obj_p_name("дорогой еде");
   set_obj_gender("female");
   set_eatable(1);
   set_gettable(1);
   set_value(90);
   set_weight(2);
}

int do_eat(void) {
   int x;

   x = random(25) + 1;
   write("Вы наслаждаетесь изысканным блюдом.");
   this_player()->query_environment()->tell_room(this_player(),
      this_player()->query_Name() + " ест изысканное блюдо.");
   this_player()->increase_hp(x);
   this_object()->destruct();
}
