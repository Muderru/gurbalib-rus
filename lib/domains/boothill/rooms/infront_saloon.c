#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("boothill");

   set_short("Главная улица");
   set_long("Вы находитесь посреди главной улицы города, густо усеянной мусором и " +
      "чьими-то харчками. На востоке судя по вывеске располагается местный паб, из которого " + 
      "доносится громкий шум");

   set_exits(([
      "север" : DIR + "/rooms/infront_store.c", 
      "юг" : DIR + "/rooms/welcome.c", 
      "восток" : DIR + "/rooms/saloon.c", 
   ]));

   set_objects(
      DIR + "/monsters/slims"
   );
}
