/* mail.c */
inherit M_COMMAND;

string subject;
string *to;
string msgdate;
string *body;

string *usage(void) {
   string all, *lines;

   if (query_admin(this_player())) {
      lines = ({  "Использование: написать [-h] [все|ИГРОК1 [ИГРОК2] [...]]" });
      all = "\tнаписать все\tОтправляет сообщение всем игрокам.";
   } else {
      lines = ({ "Использование: написать [-h] [ИГРОК1] [ИГРОК2]]" });
   }

   lines += ({ " " });
   lines += ({ "Отправляет внутри игры письмо указанным игрокам." });
   lines += ({ "Также с помощью аргумента 'все' вы можете написать всем игрокам." });
   lines += ({ "Если не указан ни один игрок, команда сообщает о " +
      "входящих сообщениях." });
   lines += ({ "В режиме письма вам доступны следующие команды:" });
   lines += ({ "\td #\tУдалить сообщение #" });
   lines += ({ "\tm ИГРОК\tОтправляет сообщение игроку" });

   if (all) {
      lines += ({ all });
   }

   lines += ({ "\tl \tПросмотреть все ваши письма." });
   lines += ({ "\tq \tВыход." });
   lines += ({ " " });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tнаписать" });
   lines += ({ "\tнаписать туор" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "delete");
   add_also("player", "look");
   add_also("player", "post");
   add_also("player", "read");
}

void delete_message(string str) {
   int x;

   if (sscanf(str, "%d", x)) {

/* XXX do the work here... delete(x); ... parse_range() would be good here. */

   } else {
      write("Чтобы удалить, вам нужно указать номер сообщения.\n");
      this_player()->input_to_object(this_object(), "view_mailbox");
   }
}

void show_menu(void) {
   write("Команды: d # (удалить сообщение) m player (написать игроку)  " +
      "l (показать почтовый ящик) q (выход)\n");
   this_player()->input_to_object(this_object(), "view_mailbox");
}

void send_message(string str) {
   if (!str || (str == "")) {
      write("Отправить сообщение? (да|нет):");
   }
   if ((str == "y") || (str == "Y") || (str == "д") || (str == "да")) {
      /* Send the message. */
   } else if ((str == "n") || (str == "N")) {
      show_menu();
   } else {
      send_message("");
   }
}

void get_subject(string str) {
   if (!str || (str == "")) {
      write("Тема: ");
      this_player()->input_to_object(this_object(), "get_subject");
   }

   subject = str;

/* XXX  body = editor results? */

   send_message("");
}

void continue_mail(string str) {
   if (!str || (str == "")) {
      write("Вы хотите продолжить? (да|нет):");
   }
   if ((str == "y") || (str == "Y") || (str == "д") || (str == "да")) {
      get_subject("");
   } else {
      show_menu();
   }
}

void verify_to(string str) {
   int x, max, error;

   if (!str || (str == "")) {
      write("Кому: ");
      this_player()->input_to_object(this_object(), "verify_to");
   } else {
      error = 0;
      if (str == "все") {
         if (query_admin(this_player())) {
            to = USER_D->list_all_users();
         } else {
            write("Вы не администратор, чтобы отправлять всем " +
               "письма сразу.\n");
            return;
         }
      } else {
         verify_to(str);
         x = 0;
         max = sizeof(to);
         while (x < max) {
            if (USER_D->player_exists(to[x])) {
               x = x + 1;
            } else {
               write("неправильный пользователь: to[x], удаление...\n");
               to[x] = "";
               error = 1;
            }
         }
      }
      if (error) {
         write("У вас несколько неправильных получателей.\nОтправить письмо : ");
         x = 0;
         while (x < max) {
            write(to[x] + " ");
         }
         continue_mail("");
      }
   }
}

void view_mailbox(string str) {
   mixed *messages;
   int x, max;
   string cmd, what;

   if (!str || (str == "")) {
   } else if ((str == "q") || (str == "quit") || (str == "выход")) {
      write("Спасибо за использование игровой почты!\n");
      return;
   } else if ((str == "d") || (str == "del") || (str == "delete") || (str == "удалить")) {
      write("Какое сообщение # вы хотите удалить:");
      this_player()->input_to_object(this_object(), "delete_message");
   } else if ((str == "l") || (str == "list") || (str == "list inbox") || (str == "список")) {
      view_mailbox("");
   } else if ((str == "m") || (str == "mail") || (str == "написать")) {
      verify_to("");
   } else {
      if (sscanf(str, "%s %s", cmd, what) != 2) {
         show_menu();
         return;
      }
      if ((cmd == "d") || (cmd == "del") || (cmd == "delete") || (str == "удалить")) {
         delete_message(what);
      }
      if ((cmd == "m") || (cmd == "mail") || (str == "написать")) {
         verify_to(what);
      }
   }

   /* messages = MAIL_D->get_messages(this_player()->query_name()); */
   if (messages) {
      max = sizeof(messages);
   } else {
      max = 0;
   }

   for (x = 0; x < max; x++) {
      write(x + "\t" + messages[x]->query_subject() + "(" +
         messages[x]->query_from() + ")\n");
   }
   if (max < 1) {
      write("У вас нет почты!\n");
   }

   show_menu();
}

static void main(string str) {

   if (!alsos) {
      setup_alsos();
   }

   write("XXX Команда 'написать' все еще в разработке.\n");
   this_player()->more(usage());
   return;

   if (empty_str(str)) {
      show_menu();
   } else {
      if (sscanf(str, "-%s", str)) {
         this_player()->more(usage());
         return;
      }

      verify_to(str);
   }
}
