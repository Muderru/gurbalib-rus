#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Поляна");
   set_long("Вы на маленькой поляне. Со всех сторон вас окружают высокие мрачные деревья. " +
      "Правда на севере, между ними, вам кажется находится небольшой просвет.");

   add_exit("север", DIR + "/rooms/plain1.c");
   add_exit("восток", DIR + "/rooms/forest1.c");
   add_exit("запад", DIR + "/rooms/forest2.c");
}
