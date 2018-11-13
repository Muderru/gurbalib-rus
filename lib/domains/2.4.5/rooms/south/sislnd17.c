#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Склон холма на острове магов");
   set_long("Вы видите здесь старый заброшенный колодец. Его " +
      "оторванная крышка валяется рядом. На востоке находятся " +
      "руины башни Арканартона. Тропинка петляет по холму на " +
      "севере и юге. Внизу она ведет в рощу на берегу. Если " +
      "посмотреть внутрь колодца, то можно заметить спускающуюся " +
      "вниз лестницу.");

   add_exit("север", DIR + "/rooms/south/sislnd12.c");
   add_exit("юг", DIR + "/rooms/south/sislnd8.c");
   add_exit("восток", DIR + "/rooms/south/sislnd18.c");
   add_exit("запад", DIR + "/rooms/south/sislnd9.c");
   add_exit("вниз", DIR + "/rooms/south/lair.c");
}
