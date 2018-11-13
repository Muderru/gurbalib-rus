#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вас окружают мрачные искривленные деревья, тянущие " +
   "к вам голые ветви, как щупальца. Окружающее безмолвие лишь иногда " +
   "прерывает жуткий крик, от которого кровь стынет в жилах.");

   add_exit("север", DIR + "/rooms/south/sforst12.c");
   add_exit("юг", DIR + "/rooms/south/sforst14.c");
   add_exit("запад", DIR + "/rooms/south/sshore5.c");
}
