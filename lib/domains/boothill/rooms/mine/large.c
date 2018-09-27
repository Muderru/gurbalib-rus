#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("mine");

   set_short("Южный туннель");
   set_long("Чем дальше вы продвигается по южному коридору в глубь горы, " +
      "тем больше и шире он становится. Видимо здесь залегала главная жила " +
      "породы, которую шахтеры интенсивно вырубали своими кирками.");

   set_exits(([
      "север" : DIR + "/rooms/mine/split.c",
      "восток" : DIR + "/rooms/mine/rough.c",
   ]));
}

