#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Берег Лунного озера");
   set_long("В этом пустынном месте вы не найдете следов животных или " +
      "птиц. Вокруг стоит мертвая тишина, а если попробовать окунуться " +
      "в воде озера, то оно начинает затягивать в глубину, замораживая " +
      "ледяной водой и сковывая движения.");

   add_exit("север", DIR + "/rooms/south/sforst30.c");
   add_exit("юг", DIR + "/rooms/south/sforst31.c");
   add_exit("северо-восток", DIR + "/rooms/south/sshore20.c");
   add_exit("юго-восток", DIR + "/rooms/south/sshore18.c");
}
