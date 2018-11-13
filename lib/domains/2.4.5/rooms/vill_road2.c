#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Деревенская деревня");
   set_long("Вы находитесь на грунтовой дороге ведущей с запада, с деревни. " +
     "Вниз по склону спускаются деревянные ступени. На севере " +
     "вы видите магазин, а на юге находится гильдия авантюристов. " +
     "Дальше на востоке начинается побережье.");

   add_exit("север", DIR + "/rooms/shop.c");
   add_exit("юг", DIR + "/rooms/adv_guild.c");
   add_exit("восток", DIR + "/rooms/vill_shore.c");
   add_exit("запад", DIR + "/rooms/vill_road1.c");
   add_exit("вниз", DIR + "/rooms/station.c");

   set_objects (DIR + "/monsters/harry.c");
}

