#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Деревенский сад");
   set_long("Вы находитесь в саду за деревенской церковью, здесь растут " +
      "отличные яблони и груши. За их душистыми плодами приходят со всей " +
      "деревни. Говорят, нет ничего вкуснее пирога из этих яблок и груш.");

   add_exit("север", DIR + "/rooms/church.c");
   add_exit("восток", DIR + "/rooms/vill_track.c");
   add_exit("запад", DIR + "/rooms/hump.c");
}
