#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("Gurba");
   add_area("BorderWalk");
   add_area("BorderWalkNorth");
   add_area("GurbaOutdoor");

   set_short("Большой перекресток");
   set_long("Вы находитесь на пересечении Пограничной улицы и Пограничного " +
      "переулка, у границы жилого квартала, большая часть которого" +
      "расположена к югу от сюда. От туда доносятся звуки " +
      "играющей детворы. Пограничный переулок тянется вдоль него с " +
      "запада на восток.");

   set_exits(([
      "восток" : DIR + "/rooms/border_north6",
      "запад" : DIR + "/rooms/border_north5",
      "юг" : DIR + "/rooms/borland3",
   ]));
}
