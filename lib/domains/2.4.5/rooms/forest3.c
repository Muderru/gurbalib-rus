#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Дебри леса");
   set_long("Вы идете по узкой тропе в самой чаще леса. Со всех сторон вас " +
   "окружают жутковатые деревья, покрытые толстым слоем мха. Из полумрака " +
   "доносятся странные звуки местных птиц и зверей. Тропа продолжается на север и " +
   "юг.");

   add_exit("север", DIR + "/rooms/slope.c");
   add_exit("юг", DIR + "/rooms/forest4.c");
}
