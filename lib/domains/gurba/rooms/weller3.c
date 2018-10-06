#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("Gurba");
   add_area("WellerAve");
   add_area("GurbaOutdoor");

   set_short("Светлая улица");
   set_long("Вы находитесь в южной части Светлой улицы. Это " +
      "отличный, но очень дорогой район для жилья. Здесь всегда " +
      "царит покой и умиротворение, и не видно мусора и бомжей. " +
      "Чуть дальше на севере расположена центральная площадь города, " +
      "а на юге улицу пересекает Пограничный переулок.");

   set_exits(([
      "север" : DIR + "/rooms/weller2",
      "юг" : DIR + "/rooms/border_weller",
   ]));
}
