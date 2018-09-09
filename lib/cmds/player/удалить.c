/* delete.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: удалить [-h] #" });
   lines += ({ "" });
   lines += ({ "позволяет вам удалить сообщение на доске сообщений." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tудалить 3" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "look");
   add_also("player", "mail");
   add_also("player", "post");
   add_also("player", "read");
}

static void main(string str) {
   object ob;
   string *lines;

   if (!alsos) {
      setup_alsos();
   }

   if (empty_str(str)) {
      this_player()->more(usage());
      return;
   }
   if (sscanf(str, "-%s", str)) {
      this_player()->more(usage());
      return;
   }

   if (this_player()->is_dead()) {
      write("Вы не можете сделать этого, пребывая в мире мертвых.\n");
      return;
   }

   ob = this_environment()->present("board");
   if (!ob) {
      write("Вы должны быть у доски сообщений для этого.\n");
      return;
   }

   if (!str || (str == "")) {
      write("Удалить что?");
      return;
   }

   if (ob->query_msg_exists(str) == 1) {
      ob->remove_message(str);
   } else {
      write("Нет такого сообщения.\n");
   }
   return;
}
