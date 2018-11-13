#include "../domain.h"
inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Гильдия авантюристов");
   set_long("Авантюристы всех мастей собираются здесь, чтобы " +
      "обсудить свои авантюристские проблемы и похвастаться " +
      "достижениями. Из дверного проема на юге бьет голубой  " +
      "свет. Также на одной из стен вы замечаете заметку.");
   add_exit("север", DIR + "/rooms/vill_road2.c");
   add_exit("юг", "/domains/required/rooms/bug_room.c");

   set_objects(DIR + "/obj/book.c");

   add_item("заметку", "Если вы ищете приключение, то добудьте " +
      "Убийцу орков у злого шамана орков и принесите его Лео.");
   add_item("заметка", "Если вы ищете приключение, то добудьте " +
      "Убийцу орков у злого шамана орков и принесите его Лео.");
}

/* If you look at the original, there was a bunch of stuff here for
   leveling up, however were doing it differently so does not apply.
   You may want to look at the old code for more info... XXX
*/
