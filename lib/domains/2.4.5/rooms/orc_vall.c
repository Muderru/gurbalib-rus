#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Долина орков");
   set_long("Эта долина была облюбована орками в качестве главного " +
      "аванпоста в этих землях. Она хорошо сокрыта в лесах и без " +
      "проводника найти ее проблематично. На севере возвышаются " +
      "зловещие постройки орков, а на востоке находится крутой склон.");
   add_exit("север", DIR + "/rooms/fortress.c");
   add_exit("восток", DIR + "/rooms/slope.c");

   set_objects (DIR + "/monsters/orc.c");
}
