#include "../../../domain.h"

inherit "/std/guild_book";

void setup(void) {
   set_id("книга");
   add_id("потертая", "книгу");
   set_long("Эта книга присоединена прочной цепью к стене. " +
      "В ней записан устав Гильдии бойцов. Потертые обложка и " +
      "страницы говорят о ее частом использовании.");
   set_short("Потертая книга");
   set_obj_i_name("потертая книга");
   set_obj_r_name("потертой книги");
   set_obj_d_name("потертой книге");
   set_obj_v_name("потертую книгу");
   set_obj_t_name("потертой книгой");
   set_obj_p_name("потертой книге");
   set_obj_gender("female");

   set_message("Добро пожаловать в Гильдию бойцов. Если вы хотите вступить " +
      "в нее, просто наберите 'вступить'. Если хотите покинуть гильдию, " +
      "наберите 'покинуть'.  Гильдия бойцов - престижное объединение " +
      "воинов.");

   set_guild("fighter");

   add_action("join_guild", "вступить");
   add_action("leave_guild", "покинуть");
}

int can_join(object player) {
   return 1;
}

int do_reject(object player) {
   write("Мастер гильдии говорит вам: Извини, ты нам не подходишь.");
   return 1;
}

int do_join(object player) {
   write("Мастер гильдии говорит вам: Добро пожаловать в Гильдию бойцов, " +
      player->query_name());
   return 1;
}

int can_leave(object player) {
   return 1;
}

int do_keep(object player) {
   write("Мастер гильдии говорит вам: Вы слишком ценны для гильдии, " +
      "я не могу вам позволить уйти.");
   return 1;
}

int do_leave(object who) {
   write("Мастер гильдии говорит вам: Печально видеть, что ты уходишь.");
   write("Мастер гильдии вздыхает.");
   write("Мастер гильдии говорит вам: Это большая потеря для Гильдии бойцов.");
   return 1;
}

