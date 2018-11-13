#include "../../domain.h"
inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумрачный лес");
   set_long("Вы находитесь в старом лесу, между деревьев стоит " +
      "густой туман за которым ничего невозможно разглядеть. Вокруг " +
      "вас раздаются непонятные шорохи и звуки. Дальше можно пройти " +
      "кажется только на север, запад и юг.");

   add_exit("север", DIR + "/rooms/forest12.c");
   add_exit("юг", DIR + "/rooms/south/sforst2.c");
   add_exit("запад", DIR + "/rooms/south/sforst5.c");
}
