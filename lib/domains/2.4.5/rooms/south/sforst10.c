#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вы находитесь в старом лесу, между деревьев стоит " +
      "густой туман за которым почти ничего невозможно разглядеть. Вокруг " +
      "вас раздаются непонятные шорохи и звуки. Дальше можно пройти " +
      "кажется только на север, запад и юг.");

   add_exit("север", DIR + "/rooms/south/sforst9.c");
   add_exit("юг", DIR + "/rooms/south/sforst11.c");
   add_exit("запад", DIR + "/rooms/south/sshore2.c");
}
