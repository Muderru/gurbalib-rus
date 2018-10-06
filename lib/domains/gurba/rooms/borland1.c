#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("Gurba");
   add_area("BorlandAve");
   add_area("GurbaOutdoor");

   set_short("Пограничная улица");
   set_long("Вы находитесь в южной части Пограничной улицы, которая " +
      "проходит через жилой квартал города. Дома здесь не такие " +
      "роскошные как на Центральной улице, но достаточно комфортные. " +
      "Городская площадь чуть дальше на юге отсюда, а улица " +
      "продолжается прямо на север.");

   set_exits(([
      "юг" : DIR + "/rooms/square_north",
      "север" : DIR + "/rooms/borland2",
   ]));
}
