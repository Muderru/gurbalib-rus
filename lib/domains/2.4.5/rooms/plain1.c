#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Равнина");
   set_long("Вы находитесь в начале большой открытой равнине, заросшей " +
   "разнотравьем. Со всех сторон вас окружают разноцветные заросли " +
   "тмина, девясила и тысячелистника. Чуть дальше на юге начинается густой лес.");

   add_exit("север", DIR + "/rooms/plain2.c");
   add_exit("юг", DIR + "/rooms/clearing.c");

   set_objects (DIR + "/monsters/wolf.c");
}
