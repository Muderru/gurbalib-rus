#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Дорога");
   set_long("Вы находитесь на дороге соединяющей рыбацкую деревню " +
      "с побережьем. С востока доносятся крики чаек и звук плещущихся " +
      "волн. Чуть дальше на западе виднеется небольшой городок.");

   add_exit("восток", DIR + "/rooms/vill_shore2.c");
   add_exit("запад", DIR + "/rooms/vill_shore.c");
}
