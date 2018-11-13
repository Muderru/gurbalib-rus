#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вы идете по Сумеречному лесу, месту мрачному и таинственному. " +
   "Вокруг вас раздаются непонятные шорохи и звуки. Находясь здесь, " +
   "начинаешь верить во все истории, ходящие об этом месте. " +
   "Даже самые дикие и невероятные.");

   add_exit("север", DIR + "/rooms/south/sshore17.c");
   add_exit("юг", DIR + "/rooms/south/sforst39.c");
   add_exit("восток", DIR + "/rooms/south/sshore16.c");
   add_exit("запад", DIR + "/rooms/south/sforst35.c");
}
