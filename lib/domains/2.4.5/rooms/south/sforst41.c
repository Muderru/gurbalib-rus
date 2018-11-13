#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вы находитесь в Сумеречном лесу. Многие деревья здесь " +
   "неестественно перекручены, вросли верхушками в землю, изгибаясь " +
   "при этом дугой, или же закаменели, становясь похожими на кости давно " +
   "почившего исполина. ");

   add_exit("север", DIR + "/rooms/south/sshore15.c");
   add_exit("восток", DIR + "/rooms/south/sshore14.c");
   add_exit("запад", DIR + "/rooms/south/sforst42.c");
}
