#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("mine");

   set_short("Разветвление");
   set_long("Шахта здесь разветвляется на два абсолютно одинаковых коридора. " +
      "Один ведет на восток, а второй на юг. На западе находится пещера, " +
      "образовавшаяся после обрушения входа.");

   set_exits(([
      "юг" : DIR + "/rooms/mine/large.c",
      "восток" : DIR + "/rooms/mine/narrow.c",
      "запад" : DIR + "/rooms/mine/mineent.c",
   ]));
}

