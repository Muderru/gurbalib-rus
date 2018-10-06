#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("Gurba");
   add_area("GurbaSquare");
   add_area("GurbaOutdoor");

   set_short("Центральная площадь - Юго-восток");
   set_long("В этой части центральной площади расположен небольшой " +
      "парк. Счастливые пары молодоженов прогуливаются здесь мимо" +
      "рядов стройных деревьев и любуются на прелестные цветы. " +
      "Это довольно милое и тихое место, излюбленное место отдыха " +
      "горожан.");

   set_exits(([
      "запад" : DIR + "/rooms/square_south",
      "север" : DIR + "/rooms/square_east",
      "северо-запад" : DIR + "/rooms/square_center",
      "юг" : DIR + "/rooms/armorshop",
   ]));

   add_item("парк", "За парком тщательно следят, так как он находится " +
      "прямо напротив особняка мэра города.");
   add_item("цветы", "Тут много всяких цветов, как местных, так и " +
      "привезенных из дальних стран.");
   add_item("деревья", "Ветки деревьев аккуратно подстрижены, это " +
      "произошло после того, как жена мэра лишилась из-за них тут глаза.");
}
