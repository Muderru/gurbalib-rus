#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("Gurba");
   add_area("BorderWalk");
   add_area("BorderWalkSouth");
   add_area("GurbaOutdoor");

   set_short("Пограничный переулок - Юг");
   set_long("Вы находитесь на Пограничном переулке - длинной и узкой " +
      "улице, которая огибает по периметру весь город. Она проложена " +
      "прямо вдоль каменной городской стены, ее неприступные бастионы " +
      "вздымаются на юге. Дальше на западе кажется поворот на " +
      "дорогу, тогда как на востоке лежит небольшой торговый " +
      "район.");

   set_exits(([
      "запад" : DIR + "/rooms/border_south1",
      "восток" : DIR + "/rooms/border_south3",
   ]));
}
