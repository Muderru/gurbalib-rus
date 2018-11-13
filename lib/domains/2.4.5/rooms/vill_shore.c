#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Дорога");
   set_long("Вы находитесь на перекрестке дорог. Северная дорога " +
      "идет вдоль восточной границы ближайшего города. Южная ведет " +
      "к полям, на которых выращиваются овощи и злаки для горожан. " +
      "Восточная же дорога ведет к побережью, а западная в " +
      "пригород.");

   add_exit("север", DIR + "/rooms/eastroad1.c");
   add_exit("юг", DIR + "/rooms/crop.c");
   add_exit("восток", DIR + "/rooms/jetty.c");
   add_exit("запад", DIR + "/rooms/vill_road2.c");
}
