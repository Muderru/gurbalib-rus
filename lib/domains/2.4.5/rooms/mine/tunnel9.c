#include "../../domain.h"
#define UP_ROOM DIR + "/rooms/mine/tunnel8.c"

inherit "/std/room";
inherit DIR + "/lib/climb_rope";

void setup(void) {
   add_area("2.4.5");

   set_short("Дыра в потолке");
   set_long("Вы стоите в древнем туннеле, тянущемся с запада на восток. " +
   "В потолке над вами зияет огромная дыра. Если бы у вас была веревка, " +
   "то вы могли бы взобраться вверх.");
   add_exit("восток", DIR + "/rooms/mine/tunnel14.c");
   add_exit("запад", DIR + "/rooms/mine/tunnel10.c");
   add_action("do_climb", "взобраться");
}

int is_rope() {
   return::is_rope(DIR + "/rooms/mine/tunnel3");
}

string query_long() {
   string str;

   str = ::query_long();
   if (is_rope()) {
      str += " " + query_extra_long(1, 0);
   }
   return str;
}

private void do_up(string str) {
   move_player(this_player(), this_object(), "вверх", UP_ROOM);
}

int do_climb(string str) {
   if (!is_rope()) {
      write("У вас нет подходящей веревки.");
      return 1;
   }
   if (str == "вверх" || str == "вверх по веревке") {
      do_up(str);
      return 1;
   }
   write("Вы должны взобраться вверх.");
   return 1;
}
