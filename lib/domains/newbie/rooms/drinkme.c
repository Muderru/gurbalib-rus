#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("newbie");

   set_short("Зал ожидания");
   set_long("Вы в небольшой грязной пещере. Она почему-то напоминает " +
      "зал ожидания. А на севере вы слышите громкие звуки.");

   set_exits(([
      "север" : DIR + "/rooms/fighting", 
      "юг" : DIR + "/rooms/quest",
   ]));

   set_objects(DIR + "/obj/table");
}
