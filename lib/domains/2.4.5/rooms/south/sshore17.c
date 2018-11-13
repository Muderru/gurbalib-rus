#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Берег Лунного озера");
   set_long("В мягкой земле берега Лунного озера вы не видите ни единого " +
      "следа животного. Даже они обходят эти гиблые места стороной. " +
      "Случайно забредшие путники пропадают тут без следа. Здесь " +
      "не стоит забывать об осторожности и терять бдительность ни на минуту.");

   add_exit("юг", DIR + "/rooms/south/sforst34.c");
   add_exit("запад", DIR + "/rooms/south/sforst33.c");
   add_exit("северо-запад", DIR + "/rooms/south/sshore18.c");
   add_exit("юго-восток", DIR + "/rooms/south/sshore16.c");
}
