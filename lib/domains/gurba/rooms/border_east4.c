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
      "вздымаются на востоке. " +
      "Прямо перед вами, на севере, вздымается величественная арка " +
      "восточных городских ворот.");

   set_exits(([
      "юг" : DIR + "/rooms/border_east3", 
      "север" : DIR + "/rooms/gate_east",
   ]));
}
