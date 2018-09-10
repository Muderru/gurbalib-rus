/* help.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: помощь [-h] [ТЕМА]" });
   lines += ({ "" });
   lines += ({ "Выдает основную информацию о: ТЕМА" });
   lines += ({ "Текущие темы:" });
   lines += ({ "\tnewbie       Если вы новичок, то начните здесь." });
   lines += ({ "\tcomm         Основы коммуникации в игре." });
   lines += ({ "\trules        Основные правила игры." });
   lines += ({ "\tbugs         Расскажет, как сообщать о багах." });
   lines += ({ "\ttime         Расскажет, как работает время в игре." });
   lines += ({ "\tchan         Расскажет о альтернативном способе общения." });

   if (query_wizard(this_player())) {
      lines += ({ "\twizard       Если вы администратор, почитайте тут." });
   }

   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tпомощь newbie" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "cmds");

   add_also("wiz", "man");
}

int show_help_for_command(string cmd) {
   string tmp;

   tmp = cmd + " -h";
   return call_other(this_player(), "do_game_command", tmp);
}

string *get_data(string filename) {
   string *lines, *tmp;
   int i, sz, where, len, width;

   width = this_player()->query_width();
   tmp = explode(read_file(filename), "\n");
   sz = sizeof(tmp);

   lines = ({ });

   for (i = 0; i < sz; i++) {
      if (strlen(tmp[i]) > width) {
         /* Big line. Break it up. */
         where = 0;
         len = strlen(tmp[i]);
         while (where < len) {
            if (where + width < len) {
               lines += ( { tmp[i][where..(where + width - 1)] } );
               where += width;
            } else {
               lines += ( { tmp[i][where..] } );
               where = len;
            }
         }
      } else {
         lines += ( { tmp[i] } );
      }
   }
   return lines;
}

int show_help(string filename) {
   string blah, *lines;
   int i, sz;

   if (file_exists(filename) < 1) {
      return 0;
   }

   lines = ( { "Помощь по " + capitalize(filename) + "." } );

   blah = "";
   sz = strlen(lines[0]);
   for (i = 0; i < sz; i++) {
      blah += "-";
   }
   lines += ( { blah } );

   lines += get_data(filename);

   this_player()->more(lines);
   return 1;
}

static void main(string arg) {
   string file;

   if (!alsos) {
      setup_alsos();
   }

   if (empty_str(arg) || (arg == "help")) {
      this_player()->more(usage());
      return;
   }

   if (sscanf(arg, "-%s", arg)) {
      this_player()->more(usage());
      return;
   }

   file = normalize_path(arg, "/doc/help/");
   if (show_help(file)) {
      return;
   }

   if (query_wizard(this_player())) {
      file = normalize_path(arg, "/doc/help/wiz/");
      if (show_help(file)) {
         return;
      }
   }

   if (show_help_for_command(arg)) {
      return;
   }

   write(capitalize(arg) + ": Неизвестный раздел помощи.");
   if (query_wizard(this_player())) {
      write("Попробуйте следующие команды помощи:\n");
      write("\tman " + arg + "\n");
      write("\t" + arg + " -h\n");
   } else {
      write("Если " + arg + " - команда, для информации по ней введите: " + 
         arg + " -h\n");
   }
   LOG_D->write_log("help", this_player()->query_Name() +
      " on " + ctime(time()) + ": " + arg + "\n");
   return;
}
