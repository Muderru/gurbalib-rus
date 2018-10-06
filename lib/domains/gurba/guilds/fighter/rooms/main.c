#include "../../../domain.h"

inherit "/std/room";

void setup(void) {
   set_short("%^BLUE%^Гильдия бойцов%^RESET%^");
   set_long("Здесь находится штаб-квартира Гильдии бойцов, что " +
      "можно определить по многочисленным вымпелам и гербам на стенах. " +
      "На севере вы видите вход в кладовые гильдии.");

   set_exits(([
      "юг" : DIR + "/guilds/fighter/rooms/entrance", 
      "север" : DIR + "/guilds/fighter/rooms/storage",
   ]));

   set_objects(DIR + "/guilds/fighter/objects/fighter_board");
}
