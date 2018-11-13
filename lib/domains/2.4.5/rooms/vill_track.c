#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Окраина деревни");
   set_long("Отсюда, с окраины деревни, на восток отходит пыльная " +
      "грунтовая дорога, которая связывает это место с остальным миром. " +
      "На западе вы видите заросшие сорняками газоны.");

   add_exit("восток", DIR + "/rooms/vill_road1.c");
   add_exit("запад", DIR + "/rooms/vill_green.c");
}
