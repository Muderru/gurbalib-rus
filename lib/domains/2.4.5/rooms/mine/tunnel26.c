#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Развилка туннелей");
   set_long("Вы остановились в разветвлении туннелей. Отсюда на " +
   "север, восток и юг отходят кажущиеся одинаковыми туннели. Вы " +
   "не видите тут никаких табличек или опознавательных знаков, " +
   "видимо нет никакой разницы, куда идти.");

   add_exit("север", DIR + "/rooms/mine/tunnel27.c");
   add_exit("юг", DIR + "/rooms/mine/tunnel25.c");
   add_exit("восток", DIR + "/rooms/mine/tunnel28.c");
}
