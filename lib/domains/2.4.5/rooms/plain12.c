#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("У края леса");
   set_long("Вы находитесь в начале большой открытой равнине, заросшей " +
   "разнотравьем. Со всех сторон вас окружают разноцветные заросли " +
   "тмина, девясила и тысячелистника. На западе равнина переходит " +
   "в густой лес.");

   add_exit("юг", DIR + "/rooms/plain10.c");
   add_exit("восток", DIR + "/rooms/plain11.c");
   add_exit("запад", DIR + "/rooms/deep_forest1.c");
}
