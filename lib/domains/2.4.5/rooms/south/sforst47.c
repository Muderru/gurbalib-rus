#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вы идете по древнему мрачному лесу, пораженному какой-то " +
   "злой магией. Деревья тут неестественно перекручены и полностью лишены " +
   "листьев. Узкие тропы ведут в южном, восточном и западном направлениях.");

   add_exit("юг", DIR + "/rooms/south/sshore27.c");
   add_exit("восток", DIR + "/rooms/south/sshore28.c");
   add_exit("запад", DIR + "/rooms/south/sforst48.c");
}
