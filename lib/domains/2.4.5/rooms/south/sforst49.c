#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вы находитесь в окружении зловещих искалеченных деревьев. " +
   "Они тянут к вам острые голые ветви, в безуспешной попытке пронзить " +
   "вас ими. Между деревьев петляют несколько узких тропок, но выведут " +
   "ли они вас куда-нибудь, не известно.");

   add_exit("юг", DIR + "/rooms/south/sshore25.c");
   add_exit("восток", DIR + "/rooms/south/sforst48.c");
   add_exit("запад", DIR + "/rooms/south/sshore24.c");
}
