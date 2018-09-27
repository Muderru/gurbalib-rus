#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("boothill");

   set_short("Перед городом");
   set_long("Узкая пыльная дорога заканчивается на севере у задворок небольшого" +
   "города. От него несет чесноком и навозом, но в целом он кажется достаточно уютным");

   set_exits(([
      "север" : DIR + "/rooms/welcome.c", 
      "запад" : DIR + "/rooms/outside_town.c",
   ]));
}
