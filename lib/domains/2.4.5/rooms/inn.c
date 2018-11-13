#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Таверна");
   set_long("Вы зашли в местную придорожную таверну, в которой можно " +
      "промочить горло после долгого пути. Хотя тут повсюду грязь и " +
      "ужасная вонь, ничего лучшего поблизости не найти. Поэтому у " +
      "владельцев таверны нет недостатка в посетителях.");

   set_objects(
        DIR + "/monsters/innkeep.c",
        "/domains/required/objects/mer_sign.c"
   );

   add_exit("восток", DIR + "/rooms/eastroad5.c");
}
