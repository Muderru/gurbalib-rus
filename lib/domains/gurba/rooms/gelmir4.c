#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("Gurba");
   add_area("GurbaOutdoor");
   add_area("GelmirRoad");

   set_short("Каменная дорога");
   set_long("Эта улица одна из самых оживленных во всем городе. " +
      "Весь день местные жители и гости Гурбы снуют по ней из " +
      "одного конца в другой, преследуя неведомые цели. " +
      "Чуть дальше на востоке вы видите восточные ворота города, " +
      "а на западе здание Гильдии бойцов.");

   set_exits(([
      "восток" : DIR + "/rooms/gate_east",
      "запад" : DIR + "/rooms/gelmir3",
   ]));
}
