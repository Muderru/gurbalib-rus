#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("Gurba");
   add_area("BorderWalk");
   add_area("BorderWalkNorth");
   add_area("GurbaOutdoor");

   set_short("Пограничный переулок - Север");
   set_long("Вы находитесь по Пограничному переулку - длинной и узкой " +
      "улице, которая огибает по периметру весь город. Она проложена " +
      "прямо вдоль каменной городской стены, ее неприступные стены " +
      "вздымаются на севере. Переулок здесь тянется прямо с севера на юг.");

   set_exits(([
      "запад" : DIR + "/rooms/border_north2",
      "восток" : DIR + "/rooms/border_north4",
   ]));
}
