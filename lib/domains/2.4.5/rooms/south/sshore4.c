#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Берег Лунного озера");
   set_long("Вы находитесь на берегу Лунного озера, в его центре вы " +
      "видите зловещий Остров магов. Вокруг него в воде плавает дохлая " +
      "рыба брюхом вверх. На восток в высохший лес ведет тропа, а " +
      "берег продолжается на север и юг.");

   add_exit("север", DIR + "/rooms/south/sshore3.c");
   add_exit("юг", DIR + "/rooms/south/sshore5.c");
   add_exit("восток", DIR + "/rooms/south/sforst12.c");
}
