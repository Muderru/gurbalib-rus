#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Кровавый грот");
   set_long("Вы зашли в большую пещеру, в которой и стены и " +
      "отдельные камни раскрашены человеческой кровью. На них " +
      "начертаны первобытные символы гигантов, свидетельствующие, " +
      "что тут находится их древнее святилище.");

   add_exit("восток", DIR + "/rooms/giant_lair.c");

  set_objects (
      DIR + "/monsters/fire_giant.c",
      DIR + "/monsters/frost_giant.c",
      DIR + "/monsters/stone_giant.c"
   );

}
