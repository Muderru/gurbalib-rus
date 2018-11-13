#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вы идете по древнему мрачному лесу, серый высохший мох " +
   "полностью приглушает ваши шаги. Вы идете в полной тишине. Время " +
   "от времени вы чувствуете на себе чей-то взгляд, но рядом вроде бы " +
   "нет никого.");

   add_exit("север", DIR + "/rooms/south/sshore18.c");
   add_exit("юг", DIR + "/rooms/south/sforst35.c");
   add_exit("восток", DIR + "/rooms/south/sshore17.c");
   add_exit("запад", DIR + "/rooms/south/sforst32.c");
}
