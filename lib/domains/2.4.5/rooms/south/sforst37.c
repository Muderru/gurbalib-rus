#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вас окружают скрюченные деревья, на которых вы не видите ни " +
   "единого зеленого листочка. Где-то рядом раздаются непонятные шорохи и " +
   "звуки. И кажется, что дуплистые деревья зловеще усмехаются " +
   "вашему страху.");

   add_exit("север", DIR + "/rooms/south/sforst36.c");
   add_exit("юг", DIR + "/rooms/south/sforst45.c");
   add_exit("восток", DIR + "/rooms/south/sforst38.c");
}
