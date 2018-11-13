#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Равнина");
   set_long("Вы находитесь на обширной равнине, тянущейся до горизонта. " +
   "Она кажется необитаемой, но это лишь из-за того, что животные едва " +
   "заслышав вас стремятся убраться подобру-поздорову. Равнина заросла " +
   "дикими травами, испускающими опьяняющий аромат.");

   add_exit("север", DIR + "/rooms/plain6.c");
   add_exit("юг", DIR + "/rooms/plain2.c");
   add_exit("восток", DIR + "/rooms/ruin.c");
   add_exit("запад", DIR + "/rooms/plain7.c");
}
