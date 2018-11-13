#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вы стоите в окружении мрачных искривленных деревьев. " +
   "На их черных ветвях нет ни единого зеленого листочка. Они тянут к " +
   "вам острые голые ветви, в безуспешной попытке пронзить " +
   "вас ими.");

   add_exit("север", DIR + "/rooms/south/sforst38.c");
   add_exit("восток", DIR + "/rooms/south/sforst43.c");
   add_exit("запад", DIR + "/rooms/south/sforst45.c");
}
