#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Берег Острова магов");
   set_long("Вы находитесь на берегу у склона холма в центре Острова магов.  " +
      "Линия берега продолжается дальше на север и юго-запад. " +
      "А на западе, на вершине холма, вы видите развалины башни " +
      "Арканартона, который жил здесь несколько столетий назад. " +
      "На полпути к вершине холма вы замечаете также древний монумент.");

   add_exit("север", DIR + "/rooms/south/sislnd4.c");
   add_exit("запад", DIR + "/rooms/south/sislnd15.c");
   add_exit("юго-запад", DIR + "/rooms/south/sislnd6.c");
}
