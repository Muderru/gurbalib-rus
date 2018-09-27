#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("mine");

   set_short("Огромная скала");
   set_long("В центре этой пещеры находится огромная скала из какого-то " +
      "очень прочного камня. Шахтеры не стали продалбливать путь сквозь нее, " +
      "а просто обогнули вокруг. На западе вы видите полуобвалившуюся пещеру, " +
      "а на юге пересечение туннелей.");

   set_exits(([
      "юг" : DIR + "/rooms/mine/passages.c",
      "восток" : DIR + "/rooms/mine/mineshaft.c",
      "запад" : DIR + "/rooms/mine/cavein.c",
   ]));

   set_objects(DIR + "/obj/bigrock.c");
}

