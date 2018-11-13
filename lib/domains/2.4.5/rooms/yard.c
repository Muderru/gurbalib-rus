#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Маленький двор");
   set_long("Вы находитесь в маленьком дворе около старых покосившихся " +
   "домиков. На востоке вы видите местный паб. А на юге проходит " +
   "пыльная дорога.");

   add_exit("юг", DIR + "/rooms/vill_road1.c");
   add_exit("восток", DIR + "/rooms/pub2.c");

   set_objects (
      DIR + "/monsters/beggar.c",
      DIR + "/obj/knife.c"
    );
}
