#include "../domain.h"

inherit "/std/object";

void setup(void) {
   set_id("пиво");
   add_ids("кружка", "кружка пива");
   set_short("Кружка пива");
   set_long("Вы видите большую кружку с желтым вонючим напитком.");
   set_obj_i_name("кружка пива");
   set_obj_r_name("кружки пива");
   set_obj_d_name("кружке пива");
   set_obj_v_name("кружку пива");
   set_obj_t_name("кружкой пива");
   set_obj_p_name("кружке пива");
   set_obj_gender("female");
   set_eatable(1);
   set_gettable(1);
   set_value(2);
   set_weight(2);
}

int do_eat(void) {
   int x;

   x = random(2) + 1;
   write("Вы осушили кружку пива.");
   this_player()->query_environment()->tell_room(this_player(),
      this_player()->query_Name() + " пьет пиво из кружки.\n");
   this_player()->increase_hp(x);
   this_object()->destruct();
   return 1;
}

int post_drop(void) {
   this_object()->query_environment()->tell_room(nil,
      "Вы слышите звон разбиваемого стекла, когда пивная кружка падает на землю.");
   this_object()->destruct();
}
