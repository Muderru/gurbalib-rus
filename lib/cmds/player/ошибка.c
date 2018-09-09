/* bug.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: ошибка [-h] ТЕМА" });
   lines += ({ "" });
   lines += ({ "Позволяет вам сообщить о баге в игре." });
   lines += ({ "Мы не можем исправить баги, если не знаем о них (и даже если знаем). :)" });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tошибка нора кролика не работает в нубской зоне" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "chan");
   add_also("player", "emote");
   add_also("player", "rsay");
   add_also("player", "say");
   add_also("player", "shout");
   add_also("player", "tell");
   add_also("player", "whisper");
   add_also("player", "wizcall");

   add_also("wiz", "echo");
   add_also("wiz", "echoto");
   add_also("wiz", "ssay");
   add_also("wiz", "sysmsg");
   add_also("wiz", "translate");
   add_also("wiz", "wizlog");

   add_also("admin", "wall");
}
private static mapping msg;
private static mapping subject;
private static mapping ob;

static void main(string str) {
   string player_name, tmp;

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

   if (!msg) {
      msg = ([]);
      subject = ([]);
      ob = ([]);
   }

   player_name = this_player()->query_Name();

   tmp = DOMAINS_DIR + "/required/rooms/bug_room";
   ob[player_name] = tmp->present("board");
   if (!ob[player_name]) {
      write("Не получается подключиться к доске сообщений об ошибках. Сообщите админам.\n");
      return;
   }

   if (!str || (str == "")) {
      subject[player_name] = "[" +
         this_player()->query_environment()->file_name() + "]";
   } else {
      subject[player_name] = str;
   }

   write(" \nПожалуйста, введите текст ниже.\n" +
      "'.' без ковычек на пустой строке до конца. ~a для отмены.\n" +
      "----------------------------------------------------------" +
      "--------------------\n");
   this_player()->input_to_object(this_object(), "enter_line");
   this_player()->set_editing(1);
   msg[player_name] = "";
}

void enter_line(string line) {
   string player_name;

   player_name = this_player()->query_Name();
   if ((line != ".") && (line != "**") && (line != "~a")) {
      if (!msg[player_name]) {
         msg[player_name] = line + "\n";
      } else {
         msg[player_name] = msg[player_name] + line + "\n";
      }
      this_player()->input_to_object(this_object(), "enter_line");
   } else {
      if (line == "~a") {
         write(" \nСообщение отменено.\n");
      } else {
         ob[player_name]->add_message(player_name,
            subject[player_name], msg[player_name]);
         write(" \nОтчет об ошибке отправлен! Спасибо вам!\n");
         CHANNEL_D->chan_send_string("wiz",
            player_name, "отправил(а) отчет об ошибке.", 1);

      }
      this_player()->set_editing(0);
      this_player()->write_prompt();
      this_environment()->tell_room(this_player(), player_name +
         " позволяет нам узнать, насколько дерьмовый этот мад.\n");
   }
}
