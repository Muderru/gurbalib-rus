#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Пещера гигантов");
   set_long("Эта пещера настолько огромна, что не удается разглядеть " +
   "ее потолок. Лишь по пронзительным крикам летучих мышей можно " +
   "догадаться о его существовании. На полу пещеры множество гигантских " +
   "следов, говорящих о том, что тут частенько бывают великаны.");

   add_exit("восток", DIR + "/rooms/giant_path.c");
   add_exit("запад", DIR + "/rooms/giant_conf.c");

   set_objects (DIR + "/monsters/giant.c");
}
