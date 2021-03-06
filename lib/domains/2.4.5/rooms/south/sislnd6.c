#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Берег Острова магов");
   set_long("Вы стоите у берега около склона холма в центре Острова магов.  " +
      "В мытной прибрежной воде плавает брюхом вверх дохлая рыба. " +
      "Чуть дальше на юго-западе, на вершине холма, вы видите развалины башни " +
      "Арканартона, который жил здесь несколько столетий назад.");

   add_exit("запад", DIR + "/rooms/south/sislnd16.c");
   add_exit("северо-восток", DIR + "/rooms/south/sislnd5.c");
   add_exit("юго-запад", DIR + "/rooms/south/sislnd7.c");
}
