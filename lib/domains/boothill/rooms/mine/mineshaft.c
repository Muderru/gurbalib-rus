#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("mine");

   set_short("Шахта");
   set_long("Вы находитесь в самых недрах горы, так глубоко как только это тут возможно. " +
      "Западный туннель перегорожен тяжелой железной дверью, сдвинуть которую будет " +
      "не так то просто из-за ржавых петель.");

   set_exits(([
      "запад" : DIR + "/rooms/mine/bigrock.c",
      "восток" : DIR + "/rooms/mine/escape.c",
   ]));

   set_objects(DIR + "/obj/irondoor.c");
}

