#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("В этом мрачном и пустынном лесу обычно царит мертвая " +
   "тишина. Здесь никогда не поют птицы, не слышно зверей. Лишь иногда " +
   "раздаются душераздирающие полные боли крики. Но их источник " +
   "всегда остается скрытым.");

   add_exit("север", DIR + "/rooms/south/sshore8.c");
   add_exit("восток", DIR + "/rooms/south/sforst18.c");
   add_exit("запад", DIR + "/rooms/south/sshore9.c");
}
