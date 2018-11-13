#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Берег Лунного озера");
   set_long("Вы стоите на берегу Лунного озера - мрачного и зловещего " +
      "места, пострадавшее в результате магического катаклизма. На " +
      "востоке от вас высохшие деревья, а с другой тухлая вонючая вода. " +
      "Берег продолжается дальше на запад и юго-восток.");

   add_exit("восток", DIR + "/rooms/south/sforst49.c");
   add_exit("запад", DIR + "/rooms/south/sshore23.c");
   add_exit("юго-восток", DIR + "/rooms/south/sshore25.c");
}
