#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Равнина");
   set_long("Вы находитесь в начале большой открытой равнине, заросшей " +
   "разнотравьем. Со всех сторон вас окружают разноцветные заросли " +
   "тмина, девясила и тысячелистника. На севере местность поднимается и " +
   "переходит в гору.");

   add_exit("север", DIR + "/rooms/mount_pass.c");
   add_exit("юг", DIR + "/rooms/plain6.c");
   add_exit("восток", DIR + "/rooms/plain13.c");
   add_exit("запад", DIR + "/rooms/plain12.c");
}
