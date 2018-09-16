#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("newbie");

   set_short("В туннеле");
   set_long("Вы внутри узкого земляного туннеля. Ползти вперед тут не так-то " +
      "просто из-за торчащих со всех сторон камней и корней. Туннель тянется дальше на юг.");

   set_exits(([
      "юг" : DIR + "/rooms/equipment",
      "запад" : DIR + "/rooms/tree", 
   ]));
}
