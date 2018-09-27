#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("mine");

   set_short("Пересечение туннелей");
   set_long("Здесь пересекаются несколько совершенно одинаковых туннелей, " +
      "и определить какой вам нужен, не так то просто.");

   set_exits(([
      "север" : DIR + "/rooms/mine/bigrock.c",
      "восток" : DIR + "/rooms/mine/deadend.c",
      "запад" : DIR + "/rooms/mine/station.c",
   ]));
}

