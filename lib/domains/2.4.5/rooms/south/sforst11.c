#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вы стоите в окружении мрачных искривленных деревьев. " +
      "На их черных ветвях нет ни единого зеленого листочка. Под " +
      "деревьями клубится густой туман, из-за которого практически " +
      "ничего не видно.");

   add_exit("север", DIR + "/rooms/south/sforst10.c");
   add_exit("юг", DIR + "/rooms/south/sforst12.c");
   add_exit("запад", DIR + "/rooms/south/sshore3.c");
}
