#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Развилка");
   set_long("Тут тянущийся с юга туннель раздваивается на два " +
   "абсолютно одинаковых ответвления, ведущих в северном и западном " +
   "направлениях. Спертый воздух тут затрудняет дыхание и от него " +
   "постоянно слезятся глаза, видимо вы уже недалеко от центра горы.");

   add_exit("север", DIR + "/rooms/mine/tunnel19.c");
   add_exit("юг", DIR + "/rooms/mine/tunnel16.c");
   add_exit("запад", DIR + "/rooms/mine/tunnel18.c");
}
