#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вы стоите на пересечении троп в Сумеречном лесу, о " +
   "котором рассказывают жуткие истории. Странники стараются обходить " +
   "эти места стороной, поэтому непонятно откуда здесь тропы. Вокруг " +
   "вас раздаются непонятные шорохи и звуки. ");

   add_exit("север", DIR + "/rooms/south/sforst48.c");
   add_exit("юг", DIR + "/rooms/south/sshore26.c");
   add_exit("восток", DIR + "/rooms/south/sshore27.c");
   add_exit("запад", DIR + "/rooms/south/sshore25.c");
}
