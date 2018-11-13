#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Лесная развилка");
   set_long("Вы забрели в самую чащобу леса. Со всех сторон вас окружают " +
   "густые кусты и мрачные деревья, по которым шныряют какие-то непонятные " +
   "твари. Отсюда все пути кажутся одинаковыми и непонятно куда дальше идти.");

   add_exit("север", DIR + "/rooms/forest8.c");
   add_exit("восток", DIR + "/rooms/forest10.c");
   add_exit("запад", DIR + "/rooms/forest11.c");
}
