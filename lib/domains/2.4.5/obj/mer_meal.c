#include "../domain.h"

inherit "/std/object";

void setup(void) {
   set_id("еда");
   add_ids("дорожная", "дорожная еда");
   set_short("Дорожная еда");
   set_long("Вы видите небольшую миску с бесформенным куском мяса. " +
   "Выглядит не очень аппетитно.");
   set_obj_i_name("дорожная еда");
   set_obj_r_name("дорожной еды");
   set_obj_d_name("дорожной еде");
   set_obj_v_name("дорожную еду");
   set_obj_t_name("дорожной едой");
   set_obj_p_name("дорожной еде");
   set_obj_gender("female");
   set_eatable(1);
   set_gettable(1);
   set_value(50);
   set_weight(2);
}

int do_eat(void) {
   int x;

   x = random(15) + 1;
   write("Вы съели дорожную еду. Она хоть и не особо вкусная, " +
      "но голод ваш утолили.\n");
   this_player()->query_environment()->tell_room(this_player(),
      this_player()->query_Name() + " ест дорожную еду.\n");
   this_player()->increase_hp(x);
   this_object()->destruct();
}
