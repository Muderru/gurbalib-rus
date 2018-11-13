#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Склон холма на острове магов");
   set_long("Вы стоите на склоне холма, где-то на полпути к его вершине. " +
      "Там, на юге, находятся руины башни архимага Арканартона. " +
      "На севере, у подножия холма вы видите мост ведущий на материк. " +
      "На востоке и западе пробегает извилистая тропа бегущая вдоль " +
      "берега острова.");

   add_exit("север", DIR + "/rooms/south/sislnd1.c");
   add_exit("юг", DIR + "/rooms/south/sislnd18.c");
   add_exit("восток", DIR + "/rooms/south/sislnd14.c");
   add_exit("запад", DIR + "/rooms/south/sislnd12.c");
}
