#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Лесная глушь");
   set_long("Похоже, что здесь давно не ступала нога человека. Тропинка" +
   "почти полностью заросла, а ветви деревьев и кустов грозятся выколоть " +
   "вам глаза. Как бы то ни было, тропа поворачивает тут с запада на север " +
   "и другого пути не видать.");

   add_exit("север", DIR + "/rooms/forest4.c");
   add_exit("запад", DIR + "/rooms/forest10.c");
}
