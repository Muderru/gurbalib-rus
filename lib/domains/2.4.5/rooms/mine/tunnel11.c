#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Туннель");
   set_long("Здесь туннель поворачивает с севера на восток, следуя за " +
   "рудоносной жилой. Видно, что эта" +
   " шахта не используется уже давно, рельсы для вагонеток изрядно " +
   "проржавели. А поддерживающие потолок балки насквозь прогнили и грозят " +
   "обрушением в любую минуту.");

   add_exit("север", DIR + "/rooms/mine/tunnel12.c");
   add_exit("восток", DIR + "/rooms/mine/tunnel10.c");
}
