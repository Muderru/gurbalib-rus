#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вы идете по древнему мрачному лесу, серый высохший мох " +
   "полностью приглушает ваши шаги. Вы идете в полной тишине. Между " +
   "деревьями мелькают неясные зловещие тени, которые моментально " +
   "растворяются, стоит только приблизится к ним.");

   add_exit("юг", DIR + "/rooms/south/sforst46.c");
   add_exit("восток", DIR + "/rooms/south/sforst47.c");
   add_exit("запад", DIR + "/rooms/south/sforst49.c");
}
