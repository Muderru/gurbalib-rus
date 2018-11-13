#include "../domain.h"

inherit "/std/room";

int current_problem;

void setup(void) {
   add_area("2.4.5");

   set_short("Паб");
   set_long("В этой небольшой забегаловке вы можете заказать " +
   "отличнейшее пойло, способное свалить с ног и коня. Тут всегда " +
   "сидят несколько никогда не просыхающих пьянчуг и что-то горячо " +
   "обсуждают. На западе сквозь полуснесенную дверь виден грязный двор.");

   set_objects(
      DIR + "/monsters/barkeep.c",
      DIR + "/monsters/goplayer.c",
      DIR + "/obj/top_list.c",
      DIR + "/obj/go.c",
      "/domains/required/objects/mer_sign.c"
   );

   add_exit("запад", DIR + "/rooms/yard.c");

   add_item("пазл", "#show_problem");
   add_item("игра", "#show_problem");
   add_item("проблема", "#show_problem");

   current_problem = 0;
}

string show_problem() {
   string result;
   if (current_problem > 2) {
      if (present("игрок")) {
         result = "Игрок выглядит уставшим.\n";
      } else {
         result = "Игральная доска сложена и игрока здесь " +
            "сейчас нет.\n";
      }
      return result;
   }

   result = "Вы смотрите на игральную доску.\n";

   if (current_problem == 0) {
      result += "5|.......\n" +
         "4|.......\n" +
         "3|@@@@@..\n" +
         "2|OOOO@..\n" +
         "1|...O@..\n" +
         " --------\n" +
         "  abcdefg\n" +
         "\nСейчас ход черных ('@').\n";
   } else if (current_problem == 1) {
      result += "7|.......\n" +
         "6|.......\n" +
         "5|@@@....\n" +
         "4|OOO@@..\n" +
         "3|O.OO@..\n" +
         "2|...O@..\n" +
         "1|..OO@..\n" +
         " --------\n" +
         "  abcdefg\n" +
         "\nСейчас ход черных ('@').\n";
   } else if (current_problem == 2) {
      result += "5|..........\n" +
         "4|...@@@@@..\n" +
         "3|@@@.O...@.\n" +
         "2|@OO@OOOO@.\n" +
         "1|@OO.O...@.\n" +
         " -----------\n" +
         "  abcdefg\n" +
         "\nСейчас ход белых ('O').\n";
   } else {
      result += "Игрок в го не хочет, чтобы его сейчас беспокоили.\n";
   }
   return result;
}

int query_current_problem() {
   return current_problem;
}

int set_current_problem(int i) {
   current_problem = i;
}
