#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Задняя комната банка");
   set_long("Вы находитесь в задней комнате банка. Как-то тут не по себе, " +
   "если вас заметит охрана, то вам не поздоровится.");

}

/* XXX Need to do door... */
