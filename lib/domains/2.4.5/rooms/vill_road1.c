#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Деревенская дорога");
   set_long("Длинная дорога ведет на восток от деревни, по направлению к " +
      "побережью. На севере и юге растут ухоженные деревья, как в парке. " +
      "На западе располагаются покосившиеся строения окраины деревни.");

   add_exit("север", DIR + "/rooms/yard.c");
   add_exit("юг", DIR + "/rooms/narr_alley.c");
   add_exit("восток", DIR + "/rooms/vill_road2.c");
   add_exit("запад", DIR + "/rooms/vill_track.c");
}
