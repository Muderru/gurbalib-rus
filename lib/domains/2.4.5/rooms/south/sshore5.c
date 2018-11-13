#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Берег Лунного озера");
   set_long("Вы стоите на берегу мертвого озера с тухлой вонючей водой. " +
      "В нем нет ни лягушек, ни рыбы, лишь их вздувшиеся останки плавают " +
      "в волнах. Отсюда в темный лес на востоке ведет узкая тропинка, " +
      "тогда как линия берега продолжается на север и юг.");

   add_exit("север", DIR + "/rooms/south/sshore4.c");
   add_exit("юг", DIR + "/rooms/south/sshore6.c");
   add_exit("восток", DIR + "/rooms/south/sforst13.c");
}
