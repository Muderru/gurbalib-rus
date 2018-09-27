#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("mine");

   set_short("Станция");
   set_long("Эта пещера была приспособлена в качестве вспомогательного помещения " +
      "для шахтеров. Повсюду вы видите перевернутые тележки и разбросанные инструменты. " +
      "Вряд ли столько добра могли забыть случайно, вероятно шахтеры планировали " +
      "вернуться сюда позже.");

   set_exits(([
      "север" : DIR + "/rooms/mine/cavein.c",
      "восток" : DIR + "/rooms/mine/passages.c",
      "запад" : DIR + "/rooms/mine/squeeze.c",
   ]));

   set_objects(DIR + "/obj/pickaxe.c");
}
