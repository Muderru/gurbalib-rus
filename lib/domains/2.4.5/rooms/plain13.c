#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Равнина");
   set_long("Вы находитесь в начале большой открытой равнине, заросшей " +
   "разнотравьем. Со всех сторон вас окружают разноцветные заросли " +
   "тмина, девясила и тысячелистника. На севере местность резко поднимается и " +
   "переходит в крутую гору.");

   add_exit("юг", DIR + "/rooms/plain8.c");
   add_exit("запад", DIR + "/rooms/plain11.c");
}
