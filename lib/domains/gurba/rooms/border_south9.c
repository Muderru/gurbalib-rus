#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("Gurba");
   add_area("BorderWalk");
   add_area("BorderWalkSouth");
   add_area("GurbaOutdoor");

   set_short("У банка Гурбы");
   set_long("Вы находитесь посреди Пограничного переулка - длинной и " +
      "узкой улице опоясывающей город по периметру. С одной стороны " +
      "она всегда ограничена городской стеной, которая в данный момент " +
      "возвышается на юге. На север ведет вымощенная булыжником дорожка " +
      "прямиком к банку города Гурба.");

   set_exits(([
      "запад" : DIR + "/rooms/border_south8",
      "восток" : DIR + "/rooms/border_south10",
      "север" : DIR + "/rooms/bank",
   ]));
}
