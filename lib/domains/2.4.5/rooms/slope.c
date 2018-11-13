#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Склон");
   set_long("Здесь лес, темнеющий на востоке и юге, начинает редеть " +
   "и постепенно заканчивается у склона на западе. Среди молодых деревьев " +
   "вы замечаете множество пней. Не так давно лес здесь интенсивно вырубали.");

   add_exit("юг", DIR + "/rooms/forest3.c");
   add_exit("восток", DIR + "/rooms/forest2.c");
   add_exit("запад", DIR + "/rooms/orc_vall.c");
}
