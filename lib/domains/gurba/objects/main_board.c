#include "../domain.h"

inherit "/std/board";

void setup(void) {
   set_id("доска");
   add_id("сообщений", "большая");
   set_board_id("main");
   set_obj_i_name("большая доска сообщений");
   set_obj_r_name("большой доски сообщений");
   set_obj_d_name("большой доске сообщений");
   set_obj_v_name("большую доску сообщений");
   set_obj_t_name("большой доской сообщений");
   set_obj_p_name("большой доске сообщений");
   set_obj_gender("female");
}

string query_short(void) {
   return "На большой доске [" + query_message_count() +
      " сообщений]";
}

string query_long(void) {
   return query_message_list(this_player()->query_name()) +
      "Команды: писать, читать #, удалить num\n";
}
