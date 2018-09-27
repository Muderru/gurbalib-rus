#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("mine");

   set_short("Сжатие туннеля");
   set_long("Шахта очень сильно сужается в этом месте, продвинуться дальше " +
      "тут можно лишь на корточках. К счастью, это сужение туннеля не тянется " +
      "сильно далеко, на западе и востоке вы видите просторные пещеры.");

   set_exits(([
      "восток" : DIR + "/rooms/mine/station.c",
      "запад" : DIR + "/rooms/mine/rough.c",
   ]));

   set_objects(DIR + "/monsters/kobold.c");
}

