#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вы находитесь в Сумеречном лесу, между деревьев стоит " +
      "густой туман за которым ничего невозможно разглядеть. Вокруг " +
      "вас раздаются непонятные шорохи и звуки. Дальше можно пройти " +
      "кажется только на север, восток и юг.");

   add_exit("север", DIR + "/rooms/south/sforst5.c");
   add_exit("юг", DIR + "/rooms/south/sforst7.c");
   add_exit("восток", DIR + "/rooms/south/sforst2.c");
}
