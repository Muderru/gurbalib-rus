#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Берег Лунного озера");
   set_long("Вы стоите у отвесных скал красноватого оттенка, на севере и " +
      "юге от вас мертвое озеро, а на востоке - высохший лес. Везде " +
      "царит мрачная картина. Окружающая тишина лишь иногда прерывается " +
      "дикими криками, полными боли и злобы.");

   add_exit("север", DIR + "/rooms/south/sshore2.c");
   add_exit("юг", DIR + "/rooms/south/sshore4.c");
   add_exit("восток", DIR + "/rooms/south/sforst11.c");
}
