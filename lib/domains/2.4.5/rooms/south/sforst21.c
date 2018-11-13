#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вы находитесь в Сумеречном лесу, месте про которое " +
   "рассказывают жуткие истории. До вас доходили слухи о проводящихся " +
   "здесь ведьминских шабашах и сатанинских обрядах по призыванию " +
   "демонов. Неизвестно, правдивы ли они, но обстановка леса располагает " +
   "ко всему этому.");

   add_exit("юг", DIR + "/rooms/south/sshore22.c");
   add_exit("восток", DIR + "/rooms/south/sshore23.c");
   add_exit("запад", DIR + "/rooms/south/sforst22.c");
}
