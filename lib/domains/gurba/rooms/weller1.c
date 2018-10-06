#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("Gurba");
   add_area("WellerAve");
   add_area("GurbaOutdoor");

   set_short("Светлая улица");
   set_long("Вы находитесь в северной части Светлой улицы в  " +
      "окружении стройных подстриженных деревьев и старых " +
      "респектабельных особняков. Выложенная брусчаткой дорога тут " +
      "лучше, чем в остальных частях города. " +
      "Дальше на севере начинается красивый парк.");

   set_exits(([
      "север" : DIR + "/rooms/square_south",
      "юг" : DIR + "/rooms/weller2",
   ]));
}
