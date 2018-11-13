#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Роща на берегу Острова магов");
   set_long("Вы находитесь в роще на берегу Острова магов. Все деревья " +
      "здесь или больны, или мертвы, или сильно мутированы. Берег острова " +
      "продолжается на восток, а роща следует за береговой линией на " +
      "запад до Точки фокусировки и на юг.");

   add_exit("юг", DIR + "/rooms/south/sislnd9.c");
   add_exit("восток", DIR + "/rooms/south/sislnd12.c");
   add_exit("запад", DIR + "/rooms/south/sislnd10.c");
}
