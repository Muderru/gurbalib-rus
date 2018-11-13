#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Чащоба");
   set_long("Вы забрели в самую чащобу леса. Со всех сторон вас окружают " +
   "густые кусты и мрачные деревья, по которым шныряют какие-то непонятные " +
   "твари. Отсюда все пути кажутся одинаковыми и непонятно куда дальше идти.");

   add_exit("север", DIR + "/rooms/forest3.c");
   add_exit("юг", DIR + "/rooms/forest7.c");
   add_exit("восток", DIR + "/rooms/forest6.c");
   add_exit("запад", DIR + "/rooms/forest5.c");
}
