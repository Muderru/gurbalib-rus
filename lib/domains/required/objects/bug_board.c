inherit "/std/board";

void setup(void) {
   set_id("доска");
   set_board_id("bug");
   set_obj_i_name("доска");
   set_obj_r_name("доски");
   set_obj_d_name("доске");
   set_obj_v_name("доску");
   set_obj_t_name("доской");
   set_obj_p_name("доске");
   set_obj_gender("female");
}

string query_short(void) {
   return "Печально известная доска багов [" + query_message_count() +
      " сообщ.]";
}

string query_long(void) {
   return query_message_list(this_player()->query_name()) + 
      "Команды: post, read #, delete num\n";
}

