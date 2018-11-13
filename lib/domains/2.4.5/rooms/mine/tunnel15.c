#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Туннель");
   set_long("Вы движетесь по туннелю, тянущемуся с востока на запад, " +
   "сверху падают капли воды и иногда комки земли. За состоянием шахты " +
   "давно никто не следил и она грозит обрушением в любую минуту.");

   add_exit("восток", DIR + "/rooms/mine/tunnel16.c");
   add_exit("запад", DIR + "/rooms/mine/tunnel14.c");
}
