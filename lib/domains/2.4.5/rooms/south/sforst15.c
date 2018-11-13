#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вы находитесь в Сумеречном лесу - мрачном и таинственном " +
   "месте, о котором ходят жуткие истории. Вокруг " +
   "вас раздаются непонятные шорохи и звуки. Дальше можно пройти " +
   "кажется только на север, запад и юг.");

   add_exit("север", DIR + "/rooms/south/sforst14.c");
   add_exit("юг", DIR + "/rooms/south/sforst16.c");
   add_exit("запад", DIR + "/rooms/south/sshore7.c");
}
