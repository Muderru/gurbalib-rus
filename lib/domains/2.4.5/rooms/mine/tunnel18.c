#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Тупик");
   set_long("Неожиданно вы зашли в тупик, заваленный горным мусором. " +
   "Вы замечаете здесь кучи щебня и шлама, а также несколько сломанных " +
   "ржавых кирок. Единственный выход ведет отсюда на восток, в поддерживаемый " +
   "гнилыми балками туннель.");

   add_exit("восток", DIR + "/rooms/mine/tunnel17.c");
}
