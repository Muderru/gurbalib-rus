#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Конная станция");
   set_long("На этой станции вы можете сесть на конный дилижанс или " + 
      "проходящую мимо карету и добраться до других городов или " +
      "проходящих станций. Здесь сильно воняет конским навозом, но " +
      "желающих уехать из этого места он не убавляет. Чуть выше " +
      "по склону проходит грунтовая дорога.");

   add_exit("вверх", DIR + "/rooms/vill_road2.c");
}
