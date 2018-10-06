#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("Gurba");
   add_area("BorderWalk");
   add_area("BorderWalkSouth");
   add_area("GurbaOutdoor");

   set_short("Перекресток Пограничного переулка и Центральной улицы ");
   set_long("Здесь Пограничный переулок пересекается с широкой " +
      "Центральной улицей, где обосновались наиболее обеспеченные " +
      "жители этого города. Вы видите там ухоженные деревья и " +
      "утонченные статуи около роскошных особняков. Пограничный " +
      "переулок же продолжается на запад и восток.");

   set_exits(([
      "восток" : DIR + "/rooms/border_south6",
      "запад" : DIR + "/rooms/border_south5",
      "север" : DIR + "/rooms/weller3",
   ]));
}
