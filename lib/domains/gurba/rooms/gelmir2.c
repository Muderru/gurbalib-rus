#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("Gurba");
   add_area("GelmirRoad");
   add_area("GurbaOutdoor");

   set_short("Каменная дорога");
   set_long("Эта улица одна из самых оживленных во всем городе. " +
      "Весь день местные жители и гости Гурбы снуют по ней из " +
      "одного конца в другой, преследуя неведомые цели. " +
      "Чуть дальше на востоке вы видите здание Гильдии бойцов, " +
      "а на западе центральную площадь.");

   set_exits(([
      "восток" : DIR + "/rooms/gelmir3",
      "запад" : DIR + "/rooms/gelmir1",
   ]));
}
