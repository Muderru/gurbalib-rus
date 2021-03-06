#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Берег Лунного озера");
   set_long("Вы стоите на берегу мертвого озера с тухлой вонючей водой. " +
      "В нем нет ни лягушек, ни рыбы, лишь их вздувшиеся останки плавают " +
      "в волнах. Отсюда в темный лес на западе ведет узкая тропинка, " +
      "тогда как линия берега продолжается на восток и юго-запад.");

   add_exit("восток", DIR + "/rooms/south/sshore24.c");
   add_exit("запад", DIR + "/rooms/south/sforst21.c");
   add_exit("юго-запад", DIR + "/rooms/south/sshore22.c");
}
