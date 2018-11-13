#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Берег Лунного озера");
   set_long("Вы стоите на берегу Лунного озера, некогда красивейшего " +
      "места. В его центре находится мрачный Остров магов. " +
      "Лесные тропы ведут отсюда на север и восток, тогда как " +
      "берег озера продолжается на юг и северо-запад.");

   add_exit("север", DIR + "/rooms/south/sforst8.c");
   add_exit("юг", DIR + "/rooms/south/sshore2.c");
   add_exit("восток", DIR + "/rooms/south/sforst9.c");
   add_exit("северо-запад", DIR + "/rooms/south/sshore30.c");
}
