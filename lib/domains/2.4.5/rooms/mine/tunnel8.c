#include "../../domain.h"
#define UP_ROOM DIR + "/rooms/mine/tunnel3.c"
#define DOWN_ROOM DIR + "/rooms/mine/tunnel9.c"

inherit "/std/room";
inherit DIR + "/lib/climb_rope";

void setup(void) {
   add_area("2.4.5");

   set_short("Шахта");
   set_long("Вы стоите прямо у шахты, опускающейся вертикально вниз. " +
   "Подняв вверх голову вы замечаете, что шахта также тянется вверх. " +
   "Если бы у вас была веревка, то вы могли бы взобраться тут.");

   add_action("do_climb", "взобраться");
}

int is_rope() {
   return::is_rope(DIR + "/rooms/mine/tunnel3");
}

string query_long() {
   string str;
   str = ::query_long();
   if (is_rope()) {
      str += " " + query_extra_long(1, 1);
   }
   return str;
}

private void do_up(string str) {
   move_player(this_player(), this_object(), "вверх", UP_ROOM);
}

private void do_down(string str) {
   move_player(this_player(), this_object(), "вниз", DOWN_ROOM);
}

int do_climb(string str) {
   if (!is_rope()) {
      write("Здесь нет подходящей веревки.");
      return 1;
   }
   if (empty_str(str)) {
      write("В каком направлении?");
      return 1;
   }
   if (str == "вверх" || str == "вверх по веревке") {
      do_up(str);
      return 1;
   }
   if (str == "вниз" || str == "вниз по веревке") {
      do_down(str);
      return 1;
   }
   write("Вы можете взобраться вверх или вниз.");
   return 1;
}
