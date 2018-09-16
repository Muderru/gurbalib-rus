#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("newbie");

   set_short("Конец туннеля");
   set_long("Вы находитесь у конца темного туннеля, в глаза вам брызжет яркий свет. " +
      "В центре комнаты установлена огромная красная кнопка, освещенная разноцветными " +
      "прожекторами.");

   set_exits(([
      "север" : DIR + "/rooms/drinkme", 
      "выход" : DIR + "/rooms/tree", ]));

   add_item("кнопка", "Это огромная красная кнопка!\nОна светится и на ней написано: Нажми меня!");
   add_item("кнопку", "Это огромная красная кнопка!\nОна светится и на ней написано: Нажми меня!");
   add_item("красная кнопка",
      "Это огромная красная кнопка!\nОна светится и на ней написано: Нажми меня!");
   add_action("do_push", "нажать");
   add_action("do_push", "надавить");
}

int do_push(string arg) {
   if ((arg == "кнопка") || (arg == "кнопку")) {
      if (this_player()->is_completed_quest("NewbieVille")) {
         write("Эта кнопка уже нажата.\n");
      } else {
         this_player()->add_completed_quest("NewbieVille");
         this_player()->increase_expr(200);
         write("Поздравляем!!!\n");
         write("Вы только что завершили квест новичка. " +
            "В награду вы получаете 200 очков опыта!\n");
      }
      return 1;
   } else {
      return 0;
   }
}
