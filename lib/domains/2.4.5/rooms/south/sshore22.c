#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Берег Лунного озера");
   set_long("Вы находитесь на берегу Лунного озера, в его центре вы " +
      "видите зловещий Остров магов. Вокруг него в воде плавает дохлая " +
      "рыба брюхом вверх. На север и запад ведут в высохший лес тропы, " +
      "берег продолжается на северо-восток и юго-запад.");

   add_exit("север", DIR + "/rooms/south/sforst21.c");
   add_exit("запад", DIR + "/rooms/south/sforst27.c");
   add_exit("северо-восток", DIR + "/rooms/south/sshore23.c");
   add_exit("юго-запад", DIR + "/rooms/south/sshore21.c");
}
