#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("Gurba");
   add_area("BorderWalk");
   add_area("BorderWalkEast");
   add_area("GurbaOutdoor");

   set_short("Пограничный переулок - Восток");
   set_long("Вы находитесь на Пограничном переулке - длинной и узкой " +
      "улице, которая огибает по периметру весь город. Она проложена " +
      "прямо вдоль каменной городской стены, ее неприступные бастионы " +
      "вздымаются на востоке. Чуть дальше на юге переулок скрывается за " +
      "углом. А прямо на севере дорога ведет к восточным воротам города.");

   set_exits(([
      "юг" : DIR + "/rooms/border_east2",
      "север" : DIR + "/rooms/border_east4",
   ]));
}
