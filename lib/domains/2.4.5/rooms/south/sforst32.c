#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Кроны окружающих деревьев громко шумят под ветром. " +
      "Сумрак скрывает практически все, что находится дальше пары " +
      "метров. Между деревьями мелькают неясные зловещие тени, " +
      "которые моментально растворяются, стоит только приблизится к ним.");

   add_exit("север", DIR + "/rooms/south/sforst31.c");
   add_exit("юг", DIR + "/rooms/south/sforst36.c");
   add_exit("восток", DIR + "/rooms/south/sforst33.c");
}
