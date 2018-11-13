#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Берег Лунного озера");
   set_long("Вы стоите на берегу Лунного озера - мрачного и зловещего " +
      "места, пострадавшее в результате магического катаклизма. На " +
      "востоке от вас высохшие деревья, а с другой тухлая вонючая вода. " +
      "Берег продолжается дальше на север и юг.");

   add_exit("север", DIR + "/rooms/south/sshore5.c");
   add_exit("юг", DIR + "/rooms/south/sshore7.c");
   add_exit("восток", DIR + "/rooms/south/sforst14.c");
}
