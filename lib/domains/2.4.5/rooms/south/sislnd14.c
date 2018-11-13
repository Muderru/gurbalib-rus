#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Склон холма на острове магов");
   set_long("Вы стоите на склоне холма, где-то на полпути к его вершине. " +
      "Там, на юго-западе, находятся руины башни архимага Арканартона,  " +
      "отсюда туда не попасть. На юге вы можете разглядеть какой-то " +
      "памятник. Обвивающая холм тропа проходит на севере, востоке и западе.");

   add_exit("север", DIR + "/rooms/south/sislnd2.c");
   add_exit("юг", DIR + "/rooms/south/sislnd15.c");
   add_exit("восток", DIR + "/rooms/south/sislnd4.c");
   add_exit("запад", DIR + "/rooms/south/sislnd13.c");
}
