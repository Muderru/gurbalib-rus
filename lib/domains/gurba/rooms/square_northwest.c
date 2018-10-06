#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("Gurba");
   add_area("GurbaSquare");
   add_area("GurbaOutdoor");

   set_short("Центральная площадь - Северо-запад");
   set_long("Если не считать нескольких бедных торговых палаток, " +
      "то в этой части площади нет ничего примечательного. Вы " +
      "можете расслышать громкое пение и крики торговцев с других " +
      "частей площади, возможно вам стоит поспешить туда.");

   set_exits(([
      "восток" : DIR + "/rooms/square_north",
      "юг" : DIR + "/rooms/square_west",
      "юго-восток" : DIR + "/rooms/square_center",
   ]));
}
