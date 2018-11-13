#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Ущелье");
   set_long("Вы сейчас находитесь в ущелье между горами и со всех " +
      "сторон вас обдувают ледяные ветра. Отсюда, цепляясь за скользкие камни, " +
      "можно попытаться взобраться вверх или опуститься вниз.");

   add_exit("вверх", DIR + "/rooms/mount_top.c");
   add_exit("вниз", DIR + "/rooms/mount_pass.c");
}
