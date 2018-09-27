#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("mine");

   set_short("Узкий проход");
   set_long("В этом узком туннеле едва протиснется взрослый человек. " +
      "Видимо шахтеры не утруждались его разработкой из-за отсутствия " +
      "полезных минералов, а может туннель образовался естественным путем.");


   set_exits(([
      "юг" : DIR + "/rooms/mine/rough.c",
      "запад" : DIR + "/rooms/mine/split.c",
   ]));
}

