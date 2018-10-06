#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("Gurba");
   add_area("GurbaSquare");
   add_area("GurbaOutdoor");

   set_short("Центральная площадь - Северо-восток");
   set_long("Эта часть площади заполнена торговцами и скоморохами, " +
      "но наибольшая активность царит на западе и юге отсюда. " +
      "Так что, если повезет найти свободное местечко, тут можно " +
      "даже немного отдохнуть от шума и гама, царящего на площади.");

   set_exits(([
      "запад" : DIR + "/rooms/square_north",
      "юг" : DIR + "/rooms/square_east",
      "юго-запад" : DIR + "/rooms/square_center",
   ]));
}
