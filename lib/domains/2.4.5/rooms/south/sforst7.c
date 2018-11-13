#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("В этом мрачном и пустынном лесу обычно царит мертвая " +
   "тишина. Здесь никогда не поют птицы, не слышно зверей. Лишь иногда " +
   "раздаются душераздирающие полные боли крики. А рядом мелькают " +
   "неясные тени.");

   add_exit("север", DIR + "/rooms/south/sforst6.c");
   add_exit("юг", DIR + "/rooms/south/sforst8.c");
   add_exit("восток", DIR + "/rooms/south/sforst3.c");
}
