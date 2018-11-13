#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Лагерь орков");
   set_long("Вы находитесь в небольшом лагере орков, вокруг вас " +
      "грубые уродливые постройки из дерева, на которых намалеваны " +
      "варварские рисунки. На севере вход в одну из таких построек.");

   set_objects (DIR + "/monsters/orc.c", DIR + "/monsters/orc.c");

   add_exit("север", DIR + "/rooms/orc_treasure.c");
   add_exit("юг", DIR + "/rooms/orc_vall.c");

}
