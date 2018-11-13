#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вы находитесь в древнем зловещем лесу. Многие деревья здесь " +
   "неестественно перекручены, вросли верхушками в землю, изгибаясь " +
   "при этом дугой, или же закаменели, становясь похожими на кости давно " +
   "умершего исполина. ");

   add_exit("север", DIR + "/rooms/south/sforst4.c");
   add_exit("юг", DIR + "/rooms/south/sforst10.c");
   add_exit("запад", DIR + "/rooms/south/sshore1.c");
}
