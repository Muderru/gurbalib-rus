#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("Gurba");
   add_area("BorderWalk");
   add_area("BorderWalkWest");
   add_area("GurbaOutdoor");

   set_short("Пограничный переулок - Запад");
   set_long("Вы находитесь посреди Пограничного переулка - длинной и " +
      "узкой улице опоясывающей город по периметру. С одной стороны " +
      "она всегда ограничена городской стеной, которая в данный момент " +
      "возвышается на западе. Чуть севернее дорога скрывается за углом, " +
      "а на юге она ведет прямиком к университету Гурбы.");

   set_exits(([
      "север" : DIR + "/rooms/border_northwest",
      "юг" : DIR + "/rooms/border_west7",
   ]));
}
