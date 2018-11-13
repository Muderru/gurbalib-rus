#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Равнина");
   set_long("Во все стороны от вас простирается обширная равнина, " +
   "заросшая разнотравьем. Душистые травы окружают вас и опьяняют " +
   "своим ароматом. На востоке ваш путь преграждает река, а на востоке " +
   "вы замечаете заброшенное здание.");

   add_exit("запад", DIR + "/rooms/ruin.c");

   set_objects (
      DIR + "/monsters/frog.c",
      DIR + "/obj/stethoscope.c"
   );
}
