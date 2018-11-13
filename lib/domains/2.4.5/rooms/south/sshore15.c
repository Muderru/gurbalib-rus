#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Берег Лунного озера");
   set_long("Здесь, на берегу Лунного озера, ничего не напоминает о тех временах, " +
      "когда оно было одним из красивейших мест в округе. Сейчас тут царит " +
      "мрачность и уныние. На запад и юг вы видите уходящие в лес тропинки, " +
      "берег озера продолжается на северо-запад и юго-восток.");

   add_exit("юг", DIR + "/rooms/south/sforst41.c");
   add_exit("запад", DIR + "/rooms/south/sforst40.c");
   add_exit("северо-запад", DIR + "/rooms/south/sshore16.c");
   add_exit("юго-восток", DIR + "/rooms/south/sshore14.c");
}
