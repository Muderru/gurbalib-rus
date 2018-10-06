#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("Gurba");
   add_area("BorderWalk");
   add_area("BorderWalkEast");
   add_area("GurbaOutdoor");

   set_short("Пограничный переулок - Восток");
   set_long("Вы пробираетесь по Пограничному переулку - длинной и узкой " +
      "улице, которая огибает по периметру весь город. Она проложена " +
      "прямо вдоль каменной городской стены, ее неприступные стены " +
      "вздымаются на востоке. Чуть дальше на севере переулок поворачивает за " +
      "угол. А прямо на юге дорога ведет к восточным воротам города.");

   set_exits(([
      "север" : DIR + "/rooms/border_northeast",
      "юг" : DIR + "/rooms/border_east7",
   ]));
}
