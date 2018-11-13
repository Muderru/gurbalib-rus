#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Множество искореженных деревьев обступают вас плотной " +
   "стеной. Откуда-то из-за нее доносятся странные звуки и скрипы, " +
   "изредка раздается вой, отдаленно похожий на собачий. Сложно " +
   "представить более жуткое место.");

   add_exit("север", DIR + "/rooms/south/sforst40.c");
   add_exit("восток", DIR + "/rooms/south/sforst41.c");
   add_exit("запад", DIR + "/rooms/south/sforst43.c");
}
