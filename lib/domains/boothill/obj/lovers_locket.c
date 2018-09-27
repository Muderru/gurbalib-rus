#include "../domain.h"

inherit "/std/armor";
inherit "/std/modules/m_readable";

int broken;
object twin;

void setup(void) {
   set_id("медальон верности");

   add_id("медальон");
   set_gettable(1);
   set_slot("apparel");
   set_obj_i_name("медальон верности");
   set_obj_r_name("медальона верности");
   set_obj_d_name("медальону верности");
   set_obj_v_name("медальон верности");
   set_obj_t_name("медальоном верности");
   set_obj_p_name("медальоне верности");
   set_obj_gender("male");

   set_short("Медальон верности");
   set_long("Медальон в виде золотого сердца с подписью ЛЮБОВЬ! " +
      "С обратной стороны медальона есть еще какая-то надпись.");
   broken = 0;

   add_action("do_breakit", "сломать");
   add_action("do_squeezeit", "сжать");

   set_message("Подумайте о своей любви, сожмите медальон и вы будете" +
      "с ней.");
   set_weight(3);
   set_size(6);
   set_value(500);
}

do_half(object obj) {
   setup();
   broken = 1;
   set_short("Половинка медальона");
   set_long("Половинка золотого сердца с выгравированными буквами " +
      "\"ЛЮБ\"! С обратной стороны тоже есть какая-то " +
      "надпись.");
   set_obj_i_name("половинка медальона");
   set_obj_r_name("половинки медальона");
   set_obj_d_name("половинке медальона");
   set_obj_v_name("половинку медальона");
   set_obj_t_name("половинкой медальона");
   set_obj_p_name("половинке медальона");
   set_obj_gender("female");
   twin = obj;
}

int do_breakit(string str) {
   if (str == "медальон верности" || str == "медальон") {
      if (broken == 1) {
         write("Медальон уже сломан.\n");
      } else { 
         object obj;

         write("Вы разломили медальон на две части.");
         if (this_player()->query_gender() == "male") {
         this_player()->query_environment()->tell_room(this_player(),
            this_player()->query_Name() + " разломил его медальон на " +
            "две части.\n");
       } else if (this_player()->query_gender() == "female") {
         this_player()->query_environment()->tell_room(this_player(),
            this_player()->query_Name() + " разломила ее медальон на " +
            "две части.\n");
       } else {
         this_player()->query_environment()->tell_room(this_player(),
            this_player()->query_Name() + " разломило его медальон на " +
            "две части.\n");
       }

         broken = 1;
         set_short("Половинка медальона");
         set_long("Половинка золотого сердца с выгравированными буквами " +
         "\"ЛЮБ\"! С обратной стороны тоже есть какая-то " +
         "надпись.");
         set_obj_i_name("половинка медальона");
         set_obj_r_name("половинки медальона");
         set_obj_d_name("половинке медальона");
         set_obj_v_name("половинку медальона");
         set_obj_t_name("половинкой медальона");
         set_obj_p_name("половинке медальона");
         set_obj_gender("female");
   
         obj = clone_object(DIR + "/obj/lovers_locket.c");
         twin = obj;
         obj->do_half(this_object());
         obj->move(this_object()->query_environment());

      }
      return 1;
   }
   return 0;
}

int do_squeezeit(string str) {
   object tmpobj;

   if (str == "медальон" || str == "медальон верности") {
      write("Вы сжали медальон и подумали о том, что вы любите.\n");
     if (this_player()->query_gender() == "male") {
      this_player()->query_environment()->tell_room(this_player(),
         this_player()->query_Name() + " сжал его медальон и замер " +
         "в задумчивости.");
   } else if (this_player()->query_gender() == "female") {
      this_player()->query_environment()->tell_room(this_player(),
         this_player()->query_Name() + " сжала ее медальон и замерла " +
         "в задумчивости.");
   } else {
      this_player()->query_environment()->tell_room(this_player(),
         this_player()->query_Name() + " сжало его медальон и замерло " +
         "в задумчивости.");
   }

      if (twin) {
         tmpobj = twin->query_environment();
         if (objectp(tmpobj) && tmpobj->query_player()) {
            tmpobj = tmpobj->query_environment();
            if (objectp(tmpobj)) {
               /* XXX Need to fix movement first...
               this_player()->magic_move(twin->query_environment()); */
               return 1;
            }
         }
      }
      write("Ты скучаешь по этому.\n");
      return 1;
   }
   return 0;
}
