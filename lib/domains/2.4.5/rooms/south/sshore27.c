#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Берег Лунного озера");
   set_long("Вы находитесь на берегу Лунного озера в центре мрачного " +
      "леса. Посреди озера темнеет зловещий Остров магов, о котором " +
      "говорят лишь шепотом. На север и запад ведут узкие лесные тропинки, " +
      "а берег озера продолжается на северо-восток и юго-запад.");

   add_exit("север", DIR + "/rooms/south/sforst47.c");
   add_exit("запад", DIR + "/rooms/south/sforst46.c");
   add_exit("северо-восток", DIR + "/rooms/south/sshore28.c");
   add_exit("юго-запад", DIR + "/rooms/south/sshore26.c");
}
