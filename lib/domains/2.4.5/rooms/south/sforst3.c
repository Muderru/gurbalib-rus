#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вы находитесь в Сумеречном лесу - мрачном и таинственном " +
   "месте, о котором ходят жуткие истории. Между деревьев петляют " +
   "несколько узких тропок, но выведут ли они вас куда-нибудь, " +
   "не известно.");

   add_exit("север", DIR + "/rooms/south/sforst2.c");
   add_exit("юг", DIR + "/rooms/south/sforst4.c");
   add_exit("запад", DIR + "/rooms/south/sforst7.c");
}
