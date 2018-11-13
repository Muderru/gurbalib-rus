#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Маленькая комната");
   set_long("Эта комната выдолблена прямо в толще скалы. На стенах " +
   "вы замечаете грубые выдолбины и следы от примитивных орудий. " +
   "Из-за низкого потолка тут невозможно выпрямиться в полный рост.");

   add_exit("юг", DIR + "/rooms/mine/tunnel5.c");

   set_objects (DIR + "/monsters/hobgoblin.c");
}
