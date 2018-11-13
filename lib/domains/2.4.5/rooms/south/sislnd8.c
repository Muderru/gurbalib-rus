#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Берег Острова магов");
   set_long("Вы стоите у кромки моря, омывающего остров магов. " +
      "К холму на востоке ведет заросшая тропинка. Тогда как берег острова " +
      "продолжается на юго-восток и северо-запад и теряется в небольшой " +
      "роще. На севере вы замечаете старый заброшенный колодец.");

   add_exit("север", DIR + "/rooms/south/sislnd17.c");
   add_exit("восток", DIR + "/rooms/south/sislnd16.c");
   add_exit("юго-восток", DIR + "/rooms/south/sislnd7.c");
   add_exit("северо-запад", DIR + "/rooms/south/sislnd9.c");
}
