#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Логово дракона");
   set_long("Вы зашли в один из многочисленных тупиков этих старых шахт. " +
   "Но, в отличие от остальных тупиков, этот был облюбован в качестве логова " +
   "молодым драконом. На полу и стенах вы видите глубокие царапины от " +
   "острых когтей. Сильный серный запах дракона раздражает ваши легкие.");

   add_exit("запад", DIR + "/rooms/mine/tunnel28.c");

   set_objects (DIR + "/monsters/dragon.c");
}
