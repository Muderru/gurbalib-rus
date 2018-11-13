#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Местная тюрьма");
   set_long("Вы оказались в местной тюрьме и отсюда нет выхода. " +
   "Остается только отбывать свой срок и надеяться, что его уменьшат " +
   "за хорошее поведение.");

   add_action("do_quit", "выход");
}

int do_quit(string str) {
   write("Вы не можете покинуть тюрьму.\n");
   return 1;
}
