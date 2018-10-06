#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("Gurba");
   add_area("BorderWalk");
   add_area("BorderWalkNorth");
   add_area("GurbaOutdoor");

   set_short("Пограничный переулок - Север");
   set_long("Вы находитесь на Пограничном переулке - длинной и узкой " +
      "улице, которая огибает по периметру весь город. Она проложена " +
      "прямо вдоль каменной городской стены, ее неприступные бастионы " +
      "вздымаются на севере. Чуть дальше на западе переулок скрывается за " +
      "углом, а на востоке тянется прямо мимо неказистых домов.");

   set_exits(([
      "запад" : DIR + "/rooms/border_north1",
      "восток" : DIR + "/rooms/border_north3",
   ]));
}
