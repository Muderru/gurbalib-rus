#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Восточная дорога");
   set_long("Вы идете по грунтовой дороге, тянущейся на север и на юг. " +
   "Под ногами в пыли множество отпечатков ног, видимо обычно тут весьма " +
   "многолюдно. На западе вы замечаете светлую алею.");

   add_exit("север", DIR + "/rooms/eastroad4.c");
   add_exit("юг", DIR + "/rooms/eastroad2.c");
   add_exit("запад", DIR + "/rooms/sunalley1.c");
}
