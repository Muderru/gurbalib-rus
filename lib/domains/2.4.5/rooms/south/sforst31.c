#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вы находитесь в окружении зловещих искалеченных деревьев. " +
   "Они тянут к вам острые голые ветви, в безуспешной попытке пронзить " +
   "вас ими. Окружающее безмолвие лишь иногда прерывает жуткий " +
   "крик, от которого кровь стынет в жилах.");

   add_exit("север", DIR + "/rooms/south/sshore19.c");
   add_exit("юг", DIR + "/rooms/south/sforst32.c");
   add_exit("восток", DIR + "/rooms/south/sshore18.c");
}
