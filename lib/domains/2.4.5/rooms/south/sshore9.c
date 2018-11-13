#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Берег Лунного озера");
   set_long("Здесь, на берегу Лунного озера, высохшие ивы опускают " +
      "свои ветви к самой кромке воды. Как будто пытаясь " +
      "напиться мертвой воды, но безуспешно. На восток в лес ведет" +
      "узкая тропинка, а берег продолжается на запад и северо-восток.");

   add_exit("восток", DIR + "/rooms/south/sforst20.c");
   add_exit("запад", DIR + "/rooms/south/sshore10.c");
   add_exit("северо-восток", DIR + "/rooms/south/sshore8.c");
}
