#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вы находитесь в старом лесу, в котором все сокрыто в " +
   "тумане. Даже в самый яркий день солнечные лучи не могут пробиться " +
   "сквозь плотную пелену тумана и здесь всегда царит сумрак.");

   add_exit("север", DIR + "/rooms/south/sforst1.c");
   add_exit("юг", DIR + "/rooms/south/sforst3.c");
   add_exit("запад", DIR + "/rooms/south/sforst6.c");
}
