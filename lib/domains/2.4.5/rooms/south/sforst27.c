#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вы стоите на пересечении троп в Сумеречном лесу, о " +
   "котором рассказывают жуткие истории. Окружающее " +
   "безмолвие лишь иногда прерывает жуткий крик, от которого " +
   "кровь стынет в жилах.");

   add_exit("север", DIR + "/rooms/south/sforst22.c");
   add_exit("юг", DIR + "/rooms/south/sshore21.c");
   add_exit("восток", DIR + "/rooms/south/sshore22.c");
   add_exit("запад", DIR + "/rooms/south/sforst26.c");
}
