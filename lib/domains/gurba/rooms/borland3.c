#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("Gurba");
   add_area("BorlandAve");
   add_area("GurbaOutdoor");

   set_short("Пограничная улица");
   set_long("Эта часть города кажется отличным местом для жизни. " +
      "Вокруг зеленеют изящные деревья, а под ними установлены " +
      "удобные скамейки. Вы слышите, как где-то рядом играют дети. " +
      "На севере Пограничная улица пересекается с Пограничным переулком, " +
      "а на юге выводит к центральной площади.");

   set_exits(([
      "юг" : DIR + "/rooms/borland2",
      "север" : DIR + "/rooms/border_borland",
   ]));
}
