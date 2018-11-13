#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Берег Лунного озера");
   set_long("Здесь, на берегу Лунного озера, ничего не напоминает о тех временах, " +
      "когда оно было одним из красивейших мест в округе. Сейчас тут царит " +
      "мрачность и уныние. На юге и востоке вы видите уходящие в лес тропинки, " +
      "а берег озера продолжается на север и юго-запад.");

   add_exit("север", DIR + "/rooms/south/sshore6.c");
   add_exit("юг", DIR + "/rooms/south/sforst19.c");
   add_exit("восток", DIR + "/rooms/south/sforst15.c");
   add_exit("юго-запад", DIR + "/rooms/south/sshore8.c");
}
