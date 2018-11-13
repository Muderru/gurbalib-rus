#include "../domain.h"

inherit "/std/room";

#ifdef USE_NOKICLIFFS
string query_long() {
   string str;

   str = ::query_long();
   str += " На востоке вы видите очертания легендарного Ноки Клиффа.";
   return str;
}
#endif

void setup(void) {
   add_area("2.4.5");

   set_short("Высокогорное плато");
   set_long("Вы на большом открытом плато недалеко от вершины горы. " +
      "Фантастический вид дополняется пушистыми облаками, до которых " +
      "кажется можно дотянуться рукой и погладить. С запада, с вершины" +
      "горы дует сильный ледяной ветер.");

#ifdef USE_NOKICLIFFS
   add_exit("восток", "/domains/nokicliffs/rooms/start.c");
#endif
   add_exit("запад", DIR + "/rooms/mount_top.c");
}
