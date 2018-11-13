#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вы стоите в окружении мрачных искривленных деревьев. " +
   "На их черных ветвях нет ни единого зеленого листочка. Окружающее " +
   "безмолвие лишь иногда прерывает жуткий крик, от которого " +
   "кровь стынет в жилах.");

   add_exit("север", DIR + "/rooms/south/sforst15.c");
   add_exit("юг", DIR + "/rooms/south/sforst17.c");
   add_exit("запад", DIR + "/rooms/south/sforst19.c");
}
