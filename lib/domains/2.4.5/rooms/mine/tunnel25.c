#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Туннель");
   set_long("Спускающаяся сверху шахта тянется здесь прямо на север. " +
   "Спертый воздух тут затрудняет дыхание и от него " +
   "постоянно слезятся глаза, видимо вы уже недалеко от центра горы.");

   add_exit("север", DIR + "/rooms/mine/tunnel26.c");
   add_exit("вверх", DIR + "/rooms/mine/tunnel24.c");
}
