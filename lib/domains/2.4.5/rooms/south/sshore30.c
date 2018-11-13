#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Берег Лунного озера");
   set_long("Вы находитесь на берегу Лунного озера в центре мрачного " +
      "леса. Посреди озера темнеет зловещий Остров магов, о котором " +
      "говорят лишь шепотом. На восток ведет узкая лесная тропинка, " +
      "а берег озера продолжается на запад и юго-восток.");

   add_exit("восток", DIR + "/rooms/south/sforst8.c");
   add_exit("запад", DIR + "/rooms/south/sshore29.c");
   add_exit("юго-восток", DIR + "/rooms/south/sshore1.c");
}
