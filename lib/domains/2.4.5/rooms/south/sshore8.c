#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Берег Лунного озера");
   set_long("Вы стоите на берегу мертвого озера с тухлой вонючей водой. " +
      "В нем нет ни лягушек, ни рыбы, лишь их вздувшиеся останки плавают " +
      "в волнах. Отсюда в мрачный лес на юг и восток ведут узкие тропинки, " +
      "тогда как берега озера продолжается на северо-восток и юго-запад.");

   add_exit("юг", DIR + "/rooms/south/sforst20.c");
   add_exit("восток", DIR + "/rooms/south/sforst19.c");
   add_exit("северо-восток", DIR + "/rooms/south/sshore7.c");
   add_exit("юго-запад", DIR + "/rooms/south/sshore9.c");
}
