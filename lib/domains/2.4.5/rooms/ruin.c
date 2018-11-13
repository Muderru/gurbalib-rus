#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Развалины");
   set_long("Вы находитесь в каких-то древних развалинах, возможно это " +
   "был домик фермера или пастуха. Сейчас у дома не осталось ни крыши, ни " +
   "окон и дверей. Со всех сторон руины дома окружает заросшее дикой травой поле.");

   add_exit("север", DIR + "/rooms/plain8.c");
   add_exit("юг", DIR + "/rooms/plain4.c");
   add_exit("восток", DIR + "/rooms/plain9.c");
   add_exit("запад", DIR + "/rooms/plain3.c");
}
