#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Берег Лунного озера");
   set_long("Вы находитесь на берегу Лунного озера, в его центре вы " +
      "видите мрачный остров с развалинами башни магов. О этом месте " +
      "ходят зловещие слухи, если они хотя бы на половину правдивы, то " +
      "вам следует бежать отсюда как можно скорее.");

   add_exit("юг", DIR + "/rooms/south/sforst40.c");
   add_exit("запад", DIR + "/rooms/south/sforst34.c");
   add_exit("северо-запад", DIR + "/rooms/south/sshore17.c");
   add_exit("юго-восток", DIR + "/rooms/south/sshore15.c");
}
