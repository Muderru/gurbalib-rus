#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вы стоите на пересечении троп в Сумеречном лесу, о " +
   "котором рассказывают жуткие истории. Путники стараются обходить " +
   "эти места стороной, поэтому странно откуда здесь тропы. Находясь здесь, " +
   "начинаешь верить во все истории, ходящие об этом месте. " +
   "Даже самые дикие и невероятные.");

   add_exit("север", DIR + "/rooms/south/sforst35.c");
   add_exit("юг", DIR + "/rooms/south/sforst44.c");
   add_exit("восток", DIR + "/rooms/south/sforst39.c");
   add_exit("запад", DIR + "/rooms/south/sforst37.c");
}
