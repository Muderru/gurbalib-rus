#include "../domain.h"

inherit "/std/object";

void setup(void) {
   set_id("стетоскоп");
   add_ids("старый", "старый стетоскоп");
   set_short("Стетоскоп");
   set_long("Этот стетоскоп выглядит старым и потертым, но использовать " +
   "его можно все-равно.");
   set_obj_i_name("старый стетоскоп");
   set_obj_r_name("старого стетоскопа");
   set_obj_d_name("старому стетоскопу");
   set_obj_v_name("старый стетоскоп");
   set_obj_t_name("старым стетоскопом");
   set_obj_p_name("старом стетоскопе");
   set_obj_gender("male");
   set_gettable(1);

   set_value(15);
   set_weight(1);
   add_action("apply", "использовать");
}

int do_listen(string str) {
   write("Вы должны приложить стетоскоп к чему-то.\n");
   this_player()->query_environment()->tell_room(this_player(),
      this_player()->query_Name() + " возится со своим стетоскопом.\n");
   return 1;
}

int apply(string str) {
   object obj;
   string what;

   if (!str) {
      return 0;
   }

   if (query_environment() != this_player()) {
      write("Чтобы использовать стетоскоп, он должен быть у вас.\n");
      return 1;
   }
   obj = this_player()->query_environment()->present(str);
   if (!obj) {
      if (sscanf(str, "стетоскоп %s", what) != 1) {
         write("На ком?\n");
         return 1;
      }
      obj = this_player()->query_environment()->present(str);
      if (!obj) {
         write("На чем?\n");
         return 1;
      }
   }

   write("Вы слушаете " + obj->query_v_name() + "\n");
   this_player()->query_environment()->tell_room(this_player(),
      this_player()->query_Name() + " слушает через стетоскоп " +
      obj->query_v_name() + ".\n");

   if (obj->is_living()) {
      write("Тук, тук.\n");
   } else {
      write("Вы не слышите ничего.\n");
   }
   return 1;
}
