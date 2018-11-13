#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вы находитесь в Сумеречном лесу - мрачном и таинственном " +
   "месте, о котором ходят жуткие истории. Вокруг вас искривленные деревья, " +
   "на которых вы не видите ни единого зеленого листочка. Лес кажется мертвым, " +
   "но и живым одновременно.");

   add_exit("север", DIR + "/rooms/south/sforst11.c");
   add_exit("юг", DIR + "/rooms/south/sforst13.c");
   add_exit("запад", DIR + "/rooms/south/sshore4.c");
}
