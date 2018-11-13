#include "../../domain.h"

inherit "/std/room";
inherit DIR + "/lib/climb_rope";

void setup(void) {
   add_area("2.4.5");

   set_short("Провал");
   set_long("Вы видите здесь под ногами огромный провал, одно " +
   "неосторожное движение и вы полетите вниз в бездонную пропасть. " +
   "Рядом с провалом в одной из стен туннеля, продолжающегося на " +
   "север и юг, вделано большое железное кольцо.");

   add_exit("север", DIR + "/rooms/mine/tunnel4.c");
   add_exit("юг", DIR + "/rooms/mine/tunnel2.c");

   add_action("do_tie", "привязать");
   add_action("do_untie", "развязать");
   add_action("do_climb", "взобраться");

   add_item("кольцо", "Кольцо крепко вделано в стену. " +
      "Возможно, вы могли бы привязать к нему веревку.");
   add_item("провал", "Провал выглядит очень глубоким и опасным.");
   set_rooms_to_notify(( {
         DIR + "/rooms/mine/tunnel8", DIR + "/rooms/mine/tunnel9"})
      );
}

int do_climb(string str) {
   if (query_tied()) {
      move_player(this_player(), this_object(), "вниз",
         DIR + "/rooms/mine/tunnel8.c");
   } else {
      write("Вы упадете в провал и скорее всего покалечитесь.\n");
      tell_room(this_player(), this_player()->query_Name() +
         " пытается спуститься вниз.\n");
   }
   return 1;
}
