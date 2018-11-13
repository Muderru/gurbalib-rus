#include "../domain.h"

inherit "/std/object";

void setup(void) {
   set_id("самогон");
   set_short("Самогон");
   set_long("Это знатное пойло, мечта любого алкаша.");
   set_obj_i_name("самогон");
   set_obj_r_name("самогона");
   set_obj_d_name("самогону");
   set_obj_v_name("самогон");
   set_obj_t_name("самогоном");
   set_obj_p_name("самогоне");
   set_obj_gender("male");
   set_eatable(1);
   set_gettable(1);
   set_value(2);
   set_weight(2);
}

int do_eat(void) {
   int x;

   x = random(2) + 1;
   write("Дрожь пробежала по вашему телу.");
   this_player()->query_environment()->tell_room(this_player(),
      this_player()->query_Name() + 
      " пьет вонючее пойло.\n");
   this_player()->increase_hp(x);
   this_object()->destruct();
}

int post_drop(void) {
   this_object()->query_environment()->tell_room(nil,
      "Вы слышите звон разбиваемого стекла, когда бутылка падает на землю.");
   this_object()->destruct();
}

