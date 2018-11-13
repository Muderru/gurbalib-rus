#include "../../domain.h"

inherit "/std/room";
inherit DIR + "/lib/maze";

void setup(void) {
   add_area("2.4.5");

   set_short("Лабиринт");
   set_long("Вы находитесь в самом настоящем лабиринте из совершенно " +
   "одинаковых полукруглых туннелях. Все стены тут покрыты противной " +
   "черной плесенью, а под ногами течет грязная вонючая вода. Тут еще и " +
   "затхлый вонючий воздух без намека свежего сквозняка.");
   add_exit("север", "#do_movementn");
   add_exit("юг", "#do_movements");
   add_exit("восток", "#do_movemente");
   add_exit("запад", "#do_movementw");

}

void do_movementn() {
   string room;
   int exit_num;

   exit_num = random(4);
   if (exit_num == 2) {
      room = DIR + "/rooms/maze1/maze2.c";
   } else {
      room = DIR + "/rooms/well.c";
   }

   goto_the(room, "север");
}

void do_movements() {
   string room;
   int exit_num;

   exit_num = random(4);
   if (exit_num == 2) {
      room = DIR + "/rooms/maze1/maze2.c";
   } else {
      room = DIR + "/rooms/well.c";
   }

   goto_the(room, "юг");
}

void do_movemente() {
   string room;
   int exit_num;

   exit_num = random(4);
   if (exit_num == 2) {
      room = DIR + "/rooms/maze1/maze2.c";
   } else {
      room = DIR + "/rooms/well.c";
   }

   goto_the(room, "восток");
}

void do_movementw() {
   string room;
   int exit_num;

   exit_num = random(4);
   if (exit_num == 2) {
      room = DIR + "/rooms/maze1/maze2.c";
   } else {
      room = DIR + "/rooms/well.c";
   }

   goto_the(room, "запад");
}
