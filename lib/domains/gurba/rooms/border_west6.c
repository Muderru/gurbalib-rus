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
      "возвышается на западе. На юге вы можете разглядеть западные " +
      "ворота города, а на севере башенки университета Гурбы.");

   set_exits(([
      "юг" : DIR + "/rooms/border_west5",
      "север" : DIR + "/rooms/border_west7",
   ]));
}
