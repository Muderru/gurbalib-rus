#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("boothill");

   set_short("Прерия");
   set_long("Все пространство на западе до горизонта занимают обширные прерии, по которым " +
      "ветра разгоняют зеленые травяные волны. Чуть дальше на востоке вы замечаете пыльную дорогу.");

   set_exits(([
      "восток" : DIR + "/rooms/entrance.c", 
      "запад" : STARTING_ROOM,
   ]));
}
