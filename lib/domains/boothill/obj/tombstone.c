#include "../domain.h"

inherit "/std/sign";

void setup(void) {
   set_id("надгробие");
   set_short("Надгробие");
   add_ids("камень", "могила", "могильное надгробие");
   set_obj_i_name("могильное надгробие");
   set_obj_r_name("могильного надгробия");
   set_obj_d_name("могильному надгробию");
   set_obj_v_name("могильное надгробие");
   set_obj_t_name("могильным надгробием");
   set_obj_p_name("могильном надгробии");
   set_obj_gender("neuter");
}

string query_long(void) {
   int x;
   string str;

   x = random(5);
   str = "Вы видите надпись на надгробии у могилы:\n\t";
   switch (x) {
      case 0:
         str += "Здесь лежит Фред, умерший от дизентерии.\n";
         break;
      case 1:
         str += "Здесь лежит Джейк, он получил удар по голове граблями.\n";
         break;
      case 2:
         str += "Здесь лежит Старик Такер. Он не смог побить мировой рекорд по выпиванию ликера.\n";
         break;
      case 3:
         str += "Тут похоронен какой-то бомж.\n";
         break;
      case 4:
         str += "Здесь лежит куртизанка Салли. Ее сгубили мужчины.\n";
         break;
   }
   return str;
}

string query_message(void) {
   return query_long();
}
