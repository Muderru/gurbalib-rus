#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("В лесу");
   set_long("Вы находитесь у кромки густого леса. Высокие стройные " +
   "деревья вздымаются кажется до облаков и почти не пропускают света. " +
   "Из глубины леса доносятся загадочные звуки.");

   add_exit("север", "/domains/required/rooms/start.c");
   add_exit("восток", DIR + "/rooms/wild1.c");
   add_exit("запад", DIR + "/rooms/clearing.c");

   set_objects (DIR + "/obj/jacket.c");
}
