#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("Gurba");
   add_area("GelmirRoad");
   add_area("GurbaOutdoor");

   set_short("Каменная дорога");
   set_long("Эта часть улицы переполнена подозрительными личностями, " +
      "закованными в доспехи и вооруженными до зубов. " +
      "Видимо их привлекла сюда Гильдия бойцов, высокое вычурное " +
      "здание которой находится на севере. " +
      "Улица же ведет с запада, с центральной площади, на восток, " +
      "к восточным воротам города.");

   set_exits(([
      "восток" : DIR + "/rooms/gelmir4",
      "запад" : DIR + "/rooms/gelmir2",
      "север" : DIR + "/guilds/fighter/rooms/entrance",
   ]));
}
