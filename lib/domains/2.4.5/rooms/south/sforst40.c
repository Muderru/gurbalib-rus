#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вы идете по мрачному и таинственному лесу. Время от " +
   "времени вам попадаются окровавленные и изуродованные трупы " +
   "животных и людей. Или не совсем людей. Но других живых существ " +
   "не видать, как будто это последние обитатели леса.");

   add_exit("север", DIR + "/rooms/south/sshore16.c");
   add_exit("юг", DIR + "/rooms/south/sforst42.c");
   add_exit("восток", DIR + "/rooms/south/sshore15.c");
   add_exit("запад", DIR + "/rooms/south/sforst39.c");
}
