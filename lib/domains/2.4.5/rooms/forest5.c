#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Лесная чащоба");
   set_long("Вы бредете по лесу по узкой тропе, возможно протоптанной " +
   "животными. Не понятно выведет ли она вас к людям, или заведет в " +
   "смертельную ловушку. Но делать нечего, надо идти на запад или восток.");

   add_exit("восток", DIR + "/rooms/forest4.c");
   add_exit("запад", DIR + "/rooms/forest8.c");
}
