#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("boothill");

   set_short("Около тюрьмы");
   set_long("Здесь, почти в самом центре города, расположено приземистое здание " +
      "местной тюрьмы. Вход в нее находится на востоке, а с севера на юг тянется грязная улица.");

   set_exits(([
      "север" : DIR + "/rooms/boothill.c", 
      "юг" : DIR + "/rooms/infront_store.c", 
      "восток" : DIR + "/rooms/jail.c", 
   ]));
}
