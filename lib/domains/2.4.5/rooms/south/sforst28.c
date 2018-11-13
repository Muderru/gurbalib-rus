#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вы идете по Сумеречному лесу, месту мрачному и таинственному. " +
   "Вас окружают голые высохшие деревья, над которыми низко зависли серые " +
   "облака, плавно переходящие в туман у поверхности земли.");

   add_exit("север", DIR + "/rooms/south/sforst26.c");
   add_exit("юг", DIR + "/rooms/south/sshore20.c");
   add_exit("восток", DIR + "/rooms/south/sshore21.c");
   add_exit("запад", DIR + "/rooms/south/sforst29.c");
}
