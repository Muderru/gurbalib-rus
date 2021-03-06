#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Узкая аллея");
   set_long("Вы находитесь на узкой аллее, между двумя рядами стройных " +
   "вечнозеленых деревьев. На востоке вы видите здание банка, а на " +
   "юге заброшенное здание. Посреди аллеи есть также колодец.");
   add_item("колодец", "Вы заглядываете внутрь колодца, но видите лишь " +
      "темноту. В стене колодца есть ряд поручней для спуска вниз.");

   add_exit("север", DIR + "/rooms/vill_road1.c");
   add_exit("юг", DIR + "/rooms/post.c");
   add_exit("восток", DIR + "/rooms/bank.c");
   add_hidden_exit("вниз", DIR + "/rooms/well.c");
}
