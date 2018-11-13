#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Берег Лунного озера");
   set_long("Вы стоите у отвесных скал красноватого оттенка, с одной " +
      "стороны от вас мертвое озеро, а с другой - высохший лес. Везде " +
      "царит мрачная картина. Окружающая тишина лишь иногда прерывается " +
      "дикими криками, полными боли и злобы.");

   add_exit("север", DIR + "/rooms/south/sforst27.c");
   add_exit("запад", DIR + "/rooms/south/sforst28.c");
   add_exit("северо-восток", DIR + "/rooms/south/sshore22.c");
   add_exit("юго-запад", DIR + "/rooms/south/sshore20.c");
}
