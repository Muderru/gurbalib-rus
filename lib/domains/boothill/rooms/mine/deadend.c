#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("mine");

   set_short("Тупик");
   set_long("Внезапно вы зашли в тупик. Видимо шахтеры разочаровались в этом " +
      "направлении из-за отсутствия породы и перестали рыть дальше. Единственный " +
      "выход ведет отсюда на запад, к пересечению туннелей.");

   set_exits(([
      "запад" : DIR + "/rooms/mine/passages.c",
   ]));

   set_objects(DIR + "/monsters/spider.c");
}

