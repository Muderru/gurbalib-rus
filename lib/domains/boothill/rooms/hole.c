#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("boothill");

   set_short("Свежевскопанная яма");
   set_long("Эту яму вырыли совсем недавно, из ее стенок торчат несколько человеческих костей. " +
   "Единственный выход отсюда ведет наверх.");
   set_light(0);

   set_exits(([
      "вверх" : DIR + "/rooms/boothill.c", 
   ]));
}
