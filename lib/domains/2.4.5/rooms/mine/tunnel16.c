#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Туннель");
   set_long("Здесь туннель резко поворачивает с севера на запад. " +
   "Около поворота растут несколько разноцветных сталагмитов, острых " +
   "как бритва. Вряд ли для роста им понадобилось много времени, с " +
   "потолка постоянно капает раствор едкой соли.");

   add_exit("север", DIR + "/rooms/mine/tunnel17.c");
   add_exit("запад", DIR + "/rooms/mine/tunnel15.c");

   set_objects (DIR + "/monsters/dwarf.c");
}
