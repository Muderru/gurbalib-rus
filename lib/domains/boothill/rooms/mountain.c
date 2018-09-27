#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("boothill");

   set_short("Одинокая гора");
   set_long("Вы вышли на расчищенное место перед горой. Дальше на востоке " +
      "находится вход в заброшенную шахту, выглядящую очень не безопасной. " +
      "А на запад в город ведет узкая тропа.");

   set_exits(([
      "восток" : DIR + "/rooms/mine/mineent.c",
      "запад" : DIR + "/rooms/mntpath.c",
   ]));
}
