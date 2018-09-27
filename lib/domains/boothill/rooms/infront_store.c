#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("boothill");

   set_short("У магазина всякой всячины");
   set_long("Вы остановились посреди главной улицы этого городка перед " +
      "магазином всякой всячины. Вход в него находится на западе. " +
      "Улица же тянется мимо неказистых зданий с севера на юг.");

   set_exits(([
      "север" : DIR + "/rooms/infront_jail.c", 
      "юг" : DIR + "/rooms/infront_saloon.c", 
      "запад" : DIR + "/rooms/general_store.c", 
   ]));
}
