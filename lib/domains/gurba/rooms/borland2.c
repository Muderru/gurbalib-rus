#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("Gurba");
   add_area("BorlandAve");
   add_area("GurbaOutdoor");

   set_short("Пограничная улица");
   set_long("В центре Пограничной улицы на удивление тихо и спокойно. " +
      "С обеих сторон на вас молчаливо взирают небольшие дома, а " +
      "откуда издалека доносится лай собак. Чуть дальше на юге " +
      "находится городская площадь, а на севере вы видите перекресток.");

   set_exits(([
      "юг" : DIR + "/rooms/borland1",
      "север" : DIR + "/rooms/borland3",
   ]));
}
