#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Склон холма на острове магов");
   set_long("Вы стоите на склоне холма, где-то на полпути к его вершине. " +
      "Там, на севере, находятся руины башни архимага Арканартона. " +
      "На востоке, западе и юге пробегает извилистая тропа огибающая " +
      "холм по спирали.");

   add_exit("север", DIR + "/rooms/south/sislnd18.c");
   add_exit("юг", DIR + "/rooms/south/sislnd7.c");
   add_exit("восток", DIR + "/rooms/south/sislnd6.c");
   add_exit("запад", DIR + "/rooms/south/sislnd8.c");
}
