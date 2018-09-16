#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("newbie");

   set_short("Узкий проход");
   set_long("Вы находитесь внутри узкого туннеля. Из земляных стен торчат камни и " +
      "корни, мешающие дальнейшему продвижению.");

   set_exits(([
      "север" : DIR + "/rooms/entrance", 
      "юг" : DIR + "/rooms/fighting",
   ]));
}
