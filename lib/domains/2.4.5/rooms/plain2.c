#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Равнина");
   set_long("Во все стороны от вас простирается обширная равнина, " +
   "заросшая разнотравьем. Душистые травы окружают вас и опьяняют " +
   "своим ароматом. Между ними снуют не крупные степные животные.");

   add_exit("север", DIR + "/rooms/plain3.c");
   add_exit("юг", DIR + "/rooms/plain1.c");
   add_exit("восток", DIR + "/rooms/plain4.c");
   add_exit("запад", DIR + "/rooms/plain5.c");
}
