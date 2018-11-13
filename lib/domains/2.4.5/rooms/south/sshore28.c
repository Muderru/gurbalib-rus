#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Берег Лунного озера");
   set_long("Здесь, на берегу Лунного озера, высохшие ивы опускают " +
      "свои ветви к самой кромке воды. Как будто пытаясь " +
      "напиться мертвой воды, но безуспешно. В лес на западе ведет" +
      "узкая тропинка, а берег продолжается на восток и юго-запад.");

   add_exit("восток", DIR + "/rooms/south/sshore29.c");
   add_exit("запад", DIR + "/rooms/south/sforst47.c");
   add_exit("юго-запад", DIR + "/rooms/south/sshore27.c");
}
