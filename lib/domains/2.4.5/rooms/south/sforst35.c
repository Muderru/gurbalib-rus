#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вы находитесь в старом лесу, в котором все сокрыто в " +
   "тумане. Даже в самый яркий день солнечные лучи не могут пробиться " +
   "сквозь плотную пелену тумана и здесь всегда царит сумрак. Между " +
   "деревьев петляют несколько узких тропок, но выведут " +
   "ли они вас куда-нибудь, не известно.");

   add_exit("север", DIR + "/rooms/south/sforst33.c");
   add_exit("юг", DIR + "/rooms/south/sforst38.c");
   add_exit("восток", DIR + "/rooms/south/sforst34.c");
   add_exit("запад", DIR + "/rooms/south/sforst36.c");
}
