#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вы стоите в окружении мрачных искривленных деревьев. " +
   "На их черных ветвях нет ни единого зеленого листочка. Между " +
   "деревьев петляют несколько узких тропок, но выведут " +
   "ли они вас куда-нибудь, не известно.");

   add_exit("север", DIR + "/rooms/south/sforst23.c");
   add_exit("юг", DIR + "/rooms/south/sforst28.c");
   add_exit("восток", DIR + "/rooms/south/sforst27.c");
   add_exit("запад", DIR + "/rooms/south/sforst25.c");
}
