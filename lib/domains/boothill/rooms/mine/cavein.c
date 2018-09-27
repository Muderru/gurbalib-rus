#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("mine");

   set_short("Обрушившаяся пещера");
   set_long("Отсыревшие опоры потолка пещеры обрушились и западная часть " +
      "пещеры оказалась полностью заваленной. Ее восточная часть также не " +
      "выглядит надежной, но пройти туда с осторожностью можно. Южная пещера " +
      "кажется вполне безопасной.");

   set_exits(([
      "юг" : DIR + "/rooms/mine/station.c",
      "восток" : DIR + "/rooms/mine/bigrock.c",
   ]));

   set_objects(DIR + "/obj/rubble.c");
}

