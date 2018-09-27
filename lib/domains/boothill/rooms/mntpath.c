#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("boothill");

   set_short("Узкая тропа");
   set_long("Узкая тропа ведет через рощу кривых деревьев на восток, по направлению " +
      "к одинокой горе. На западе же находится городское кладбище.");

   set_exits(([
      "восток" : DIR + "/rooms/mountain.c",
      "запад" : DIR + "/rooms/boothill.c",
   ]));
}
