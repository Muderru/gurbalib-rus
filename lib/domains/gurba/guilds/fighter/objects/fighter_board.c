inherit "/std/board";

void setup(void) {
   if (clone_num() == 0) {
      return;
   }
   if (!query_environment()) {
      return;
   }
   set_id("доска");
   add_id("сообщений", "большая");
   set_board_id("fighter");
   set_obj_i_name("доска сообщений Гильдии бойцов");
   set_obj_r_name("доски сообщений Гильдии бойцов");
   set_obj_d_name("доске сообщений Гильдии бойцов");
   set_obj_v_name("доску сообщений Гильдии бойцов");
   set_obj_t_name("доской сообщений Гильдии бойцов");
   set_obj_p_name("доске сообщений Гильдии бойцов");
   set_obj_gender("female");
}

string query_short(void) {
   return "На доске сообщений Гильдии бойцов [" +
      query_message_count() + " сообщений]";
}

string query_long(void) {
   return query_message_list(this_player()->query_name()) +
      "Команды: писать, читать #, удалить num\n";
}

