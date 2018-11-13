#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("В лесу");
   set_long("Вы находитесь у кромки мрачного леса. Со всех сторон вас " +
   "окружают жутковатые деревья, покрытые толстым слоем мха. Из полумрака " +
   "доносятся странные звуки местных птиц и зверей. На востоке же вы " +
   "видите кажущуюся мирной поляну.");

   add_exit("восток", DIR + "/rooms/clearing.c");
   add_exit("запад", DIR + "/rooms/slope.c");

  set_objects (DIR + "/monsters/troll.c");
}
