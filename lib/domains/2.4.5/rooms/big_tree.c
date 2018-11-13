#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Большое дерево");
   set_long("Посреди поля стоит высокое дерево. Кажется оно очень старое и " +
   "пережило не один ураган. Кроме того, на дереве видны следы ударов молний. " +
   "Дальше на западе вы видите широкую дорогу.");

   add_exit("восток", DIR + "/rooms/plain7.c");
   add_exit("запад", DIR + "/rooms/giant_path.c");

   add_item("дерево", "Ветки очень высоко, даже и не стоит лезть на него.");

   add_action("climb", "лезть");

   set_objects (DIR + "/obj/rope.c");
}

int climb(string arg) {
   this_player()->query_environment()->tell_room(this_player(),
      this_player()->query_Name() + " смотрит вверх на дерево.\n");
   write("Вы не можете дотянуться до веток.\n");
   return 1;
}
