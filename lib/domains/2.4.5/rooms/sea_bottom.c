#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Морское дно");
   set_long("Вы на дне. Нет, не на том где вы бываете обычно, а на " +
   "морском. Вокруг вас медленно покачиваются длинные водоросли и " +
   "снуют стайки разноцветных рыб. Несколько морских коньков с интересом " +
   "наблюдают за вами, не понимая, что вы тут забыли.");

   add_exit("вверх", DIR + "/rooms/sea.c");

   set_objects (DIR + "/monsters/octopus.c");
#ifdef USE_NOKICLIFFS
   add_object(NOKICLIFFS_SEASHELL, 1);
#endif
}
