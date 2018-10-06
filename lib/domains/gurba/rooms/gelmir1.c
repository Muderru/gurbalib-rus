#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("Gurba");
   add_area("GelmirRoad");
   add_area("GurbaOutdoor");

   set_short("Каменная дорога");
   set_long("Выложенная из гальки дорога ведет прямо к городской площади " +
      "на западе. Туда и оттуда движется огромная толпа народа, " +
      "многие несут большие корзины и огромные тюки. Чуть дальше " +
      "на востоке вы видите вход в высокое вычурное здание.");

   set_exits(([
      "восток" : DIR + "/rooms/gelmir2",
      "запад" : DIR + "/rooms/square_east",
   ]));
}
