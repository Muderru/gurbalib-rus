#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Берег Лунного озера");
   set_long("Вы стоите на берегу Лунного озера - мрачного и зловещего " +
      "места, пострадавшее в результате магического катаклизма. С одной " +
      "стороны от вас высохшие деревья, а с другой тухлая вонючая вода. " +
      "Берег продолжается дальше на запад и восток.");

   add_exit("восток", DIR + "/rooms/south/sshore12.c");
   add_exit("запад", DIR + "/rooms/south/sshore14.c");
}
