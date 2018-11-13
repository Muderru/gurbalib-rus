#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Равнина");
   set_long("Вы находитесь на большой открытой равнине, заросшей " +
   "разнотравьем. Со всех сторон вас окружают разноцветные заросли " +
   "тмина, девясила и тысячелистника. На западе вы замечаете огромное " +
   "старое дерево.");

   add_exit("север", DIR + "/rooms/plain10.c");
   add_exit("юг", DIR + "/rooms/plain5.c");
   add_exit("восток", DIR + "/rooms/plain3.c");
   add_exit("запад", DIR + "/rooms/big_tree.c");
}
