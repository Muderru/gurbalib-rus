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
      "возвышается на западе. Переулок продолжается на север и юг. " +
      "Чуть дальше на севере вы видите западные ворота города.");

   set_exits(([
      "юг" : DIR + "/rooms/border_west2",
      "север" : DIR + "/rooms/border_west4",
   ]));
}
