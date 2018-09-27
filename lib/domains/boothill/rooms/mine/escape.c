#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("mine");

   set_short("Выход");
   set_long("После долгого блуждания по этим шахтам, вы нашли наконец " +
      "из них выход. Из огромного пролома в стене на востоке брызжет " +
      "яркий свет. Если же вы передумали выбираться отсюда, то западный" +
      "туннель приведет вас в недра горы.");

   add_action("move_rubble", "двигать");
   add_action("move_rubble", "сдвинуть");

   add_item("пролом", "Пролом завален несколькими крупными камнями, " +
      "которые если поднапрячься можно сдвинуть.");

   set_exits(([
      "запад" : DIR + "/rooms/mine/mineshaft.c",
   ]));
}

int move_rubble(string str) {
   if (str == "камни") {
      write("Вы уперлись обеими руками в камни и начали потихоньку " +
         "сдвигать их в сторону.");
            if (this_player()->query_gender() == "male") {
      this_environment()->tell_room(this_player(), this_player()->query_Name() +
         " сдвинул камни и вышел наружу.");
          } else if (this_player()->query_gender() == "female") {
      this_environment()->tell_room(this_player(), this_player()->query_Name() +
         " сдвинула камни и вышел наружу.");
          } else {
      this_environment()->tell_room(this_player(), this_player()->query_Name() +
         " сдвинуло камни и вышел наружу.");
       }

      this_player()->move(DIR + "/rooms/mntpath.c");
      return 1;
   } 
   return 0;
}
