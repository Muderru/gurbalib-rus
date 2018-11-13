#include "../../domain.h"

inherit "/std/room";
inherit DIR + "/lib/maze";

void setup(void) {
   add_area("2.4.5");

   set_short("Конец лабиринта");
   set_long("Кажется наконец вы достигли конца лабиринта и очутились в тупике. " +
   "Позади осталось переплетение одинаковых туннелей, через которые вам, " +
   "по всей видимости, придется снова пройти.");

   add_exit("юг", DIR + "/rooms/maze1/maze4.c");

   set_objects (DIR + "/obj/leather.c");
}
