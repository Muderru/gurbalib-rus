#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Тропа");
   set_long("Вы находитесь на тропе, ведущей с запада восток. Вокруг " +
      "нее множество следов каких-то огромных существ. И лучше вам не " +
      "тревожить их, даже добрый великан может растоптать вас ненароком.");

   add_exit("восток", DIR + "/rooms/big_tree.c");
   add_exit("запад", DIR + "/rooms/giant_lair.c");
}
