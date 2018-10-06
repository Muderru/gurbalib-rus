#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("Gurba");
   add_area("BorderWalk");
   add_area("BorderWalkNorth");
   add_area("GurbaOutdoor");

   set_short("Пограничный переулок - Север");
   set_long("Вы находитесь на Пограничном переулке - длинной и узкой " +
      "улице, огибающей город Гурба по периметру, тянется здесь прямо с " +
      "запада на восток. Неприступные стены города возвышаются на севере, " +
      "а на юге взгляд упирается в глухие стены домов.");

   set_exits(([
      "запад" : DIR + "/rooms/border_north9",
      "восток" : DIR + "/rooms/border_northeast",
   ]));
}
