#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вы находитесь в старом лесу, между деревьев стоит " +
   "густой туман за которым ничего невозможно разглядеть. Вокруг вас " +
   "искривленные деревья, на которых вы не видите ни единого зеленого " +
   "листочка. Лес кажется мертвым, но и живым одновременно.");

   add_exit("север", DIR + "/rooms/south/sforst13.c");
   add_exit("юг", DIR + "/rooms/south/sforst15.c");
   add_exit("запад", DIR + "/rooms/south/sshore6.c");
}
