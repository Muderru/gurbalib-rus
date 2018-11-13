#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Берег Острова магов");
   set_long("Вы находитесь на каменистом берегу Острова магов. " +
      "На сколько вы можете видеть, он продолжается на север и юг отсюда. " +
      "На западе местность поднимается, там расположен большой холм " +
      "с развалинами башни Арканартона.");

   add_exit("север", DIR + "/rooms/south/sislnd3.c");
   add_exit("юг", DIR + "/rooms/south/sislnd5.c");
   add_exit("запад", DIR + "/rooms/south/sislnd14.c");
}
