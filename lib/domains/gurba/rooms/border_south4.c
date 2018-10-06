#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("Gurba");
   add_area("BorderWalk");
   add_area("BorderWalkSouth");
   add_area("GurbaOutdoor");

   set_short("Пограничный переулок - Юг");
   set_long("Вы находитесь посреди Пограничного переулка - длинной и " +
      "узкой улице опоясывающей город по периметру. С одной стороны " +
      "она всегда ограничена городской стеной, которая в данный момент " +
      "возвышается на юге. Переулок проходит тут через небольшой торговый " +
      "квартал и продолжается дальше на запад и восток.");

   set_exits(([
      "запад" : DIR + "/rooms/border_south5",
      "восток" : DIR + "/rooms/border_south3",
   ]));
}
