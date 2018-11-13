#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вы стоите на пересечении троп в Сумеречном лесу, о " +
   "котором рассказывают жуткие истории. Путники стараются обходить " +
   "эти места стороной, поэтому странно откуда здесь тропы.");

   add_exit("север", DIR + "/rooms/south/sforst19.c");
   add_exit("восток", DIR + "/rooms/south/sforst17.c");
   add_exit("запад", DIR + "/rooms/south/sforst20.c");
}
