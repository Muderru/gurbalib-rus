#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вы находитесь в Сумеречном лесу, месте про которое " +
   "рассказывают жуткие истории. Откуда-то из-за деревьев доносятся " +
   "странные звуки и скрипы, изредка раздается вой, отдаленно " +
   "похожий на собачий. Сложно представить более жуткое место.");

   add_exit("север", DIR + "/rooms/south/sforst7.c");
   add_exit("юг", DIR + "/rooms/south/sshore1.c");
   add_exit("восток", DIR + "/rooms/south/sforst4.c");
   add_exit("запад", DIR + "/rooms/south/sshore30.c");
}
