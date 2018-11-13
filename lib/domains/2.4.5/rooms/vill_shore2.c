#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Побережье");
   set_long("Вы находитесь на побережье около рыбачкой деревни. На " +
      "востоке вы видите причал с лодками и снастями. На севере - пляж. " +
      "На запад отсюда ведет грунтовая дорога.");

   add_exit("восток", DIR + "/rooms/jetty2.c");
   add_exit("запад", DIR + "/rooms/jetty.c");
}
