#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Здесь звериная тропа поворачивает с юга на восток, " +
   "огибая искривленные прогнившие деревья, тянущие к вам острые " +
   "голые ветви, как пики. Вокруг вас раздаются непонятные шорохи " +
   "и звуки. Лес кажется мертвым, но и живым одновременно.");

   add_exit("юг", DIR + "/rooms/south/sforst25.c");
   add_exit("восток", DIR + "/rooms/south/sforst23.c");
}
