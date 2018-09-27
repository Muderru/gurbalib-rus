#include "../domain.h"

inherit "/std/armor";
inherit "/std/modules/m_readable";

string get_color(void) {

   switch(random(5)) {
      case 0:
         return "Красная";
      case 1:
         return "Голубая";
      case 2:
         return "Белая";
      case 3:
         return "Черная";
      default:
         return "Оранжевая";
   }
}

int set_color(string str) {
   if (!str || str == "") {
      str = get_color();
   }

   set_adj(str);
   set_short(str + " бандана");
   set_long(str + " бандана, вроде выглядит очень стильно. А еще " +
      "на ней висит маленькая этикетка.");
}

void setup(void) {
   set_id("бандана", "платок", "этикетка");
   set_color("");
   set_obj_i_name("бандана");
   set_obj_r_name("банданы");
   set_obj_d_name("бандане");
   set_obj_v_name("бандану");
   set_obj_t_name("банданой");
   set_obj_p_name("бандане");
   set_obj_gender("female");
   set_gettable(1);
   set_slot("apparel");

   add_action("do_shakeit", "отжать");

   set_message("Вы видите надпись на этикетке: Только ручная стирка.\n" +
      "Чтобы высушить, бандану нужно сильно отжать.");
   set_weight(3);
   set_size(6);
   set_value(5);
}

int do_shakeit(string str) {
   if (str == "платок" || str == "бандана" || str == "бандану") {
      write("Вы сильно отжали бандану.");
           if (this_player()->query_gender() == "male") {
      this_player()->query_environment()->tell_room(this_player(),
         this_player()->query_Name() + " сильно отжал мокрую " +
         "бандану.\n");
          } else if (this_player()->query_gender() == "female") {
      this_player()->query_environment()->tell_room(this_player(),
         this_player()->query_Name() + " сильно отжала мокрую " +
         "бандану.\n");
          } else {
      this_player()->query_environment()->tell_room(this_player(),
         this_player()->query_Name() + " сильно отжало мокрую " +
         "бандану.\n");
       }

      write("Бандана потеряла свой цвет.");

      set_color("");
      return 1;
   }
   return 0;
}
