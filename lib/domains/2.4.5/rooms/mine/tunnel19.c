#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Туннель");
   set_long("Вы находитесь в шахте, тянущейся с севера на юг, куда-то " +
   "в глубь горы. Чем ниже опускаетесь, тем горячее и вонючее становится " +
   "воздух, от минеральных газов. За туннелем уже давно никто не следит " +
   "и он может рухнуть в любую минуту.");

   add_exit("север", DIR + "/rooms/mine/tunnel22.c");
   add_exit("юг", DIR + "/rooms/mine/tunnel17.c");
}
