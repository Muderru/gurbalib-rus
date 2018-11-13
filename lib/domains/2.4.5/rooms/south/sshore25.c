#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Берег Лунного озера");
   set_long("Здесь, на берегу Лунного озера, ничего не напоминает о тех временах, " +
      "когда оно было одним из красивейших мест в округе. Сейчас тут царит " +
      "мрачность и уныние. На севере и востоке вы видите уходящие в лес тропинки, " +
      "а берег озера продолжается на северо-запад и юго-восток.");

   add_exit("север", DIR + "/rooms/south/sforst49.c");
   add_exit("восток", DIR + "/rooms/south/sforst46.c");
   add_exit("северо-запад", DIR + "/rooms/south/sshore24.c");
   add_exit("юго-восток", DIR + "/rooms/south/sshore26.c");
}
