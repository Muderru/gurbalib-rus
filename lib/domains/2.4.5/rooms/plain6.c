#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Равнина");
   set_long("Вы находитесь на большой равнине, заросшей дикими травами. " +
   "Она кажется необитаемой, но это лишь из-за того, что животные едва " +
   "заслышав вас стремятся убраться подобру-поздорову. Лишь любопытные " +
   "сурки наблюдают за вами с интересом.");

   add_exit("север", DIR + "/rooms/plain11.c");
   add_exit("юг", DIR + "/rooms/plain3.c");
   add_exit("восток", DIR + "/rooms/plain8.c");
   add_exit("запад", DIR + "/rooms/plain10.c");
}
