/* set.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: настройки [-h] [VAR VALUE]" });
   lines += ({ " " });
   lines += ({ "Позволяет вам изменить настройки вашего аккаунта." });
   lines += ({ "Если не указана пара параметров VAR VALUE, будут выведены на экран ваши текущие настройки."
      });
   lines += ({ "Настройки, которые вы можете изменить:" });
   lines += ({ "\theight\t\tВысота вашего экрана.  " +
    "Установите 0 для максимальной высоты, 1 значение по умолчанию или используйте свое значение." });
   lines += ({ "\twidth\t\tШирина вашего экрана." });
   lines += ({ "\tprompt\t\tВаша строка состояния." });
   if (!query_guest(this_player()->query_name() ) ) {
      lines += ({ "\trealname\t\tВаше реальное имя." });
      lines += ({ "\email\t\tВаш email." });
      lines += ({ "\twww\t\tВаш веб-сайт." });
   }
   if (query_wizard(this_player() ) ) {
      lines += ({ "\tstart\t\tВашу стартовую комнату." });
      lines += ({ "\thidden\t\tУстановите 1, если хотите скрыть ваш вход в игру " +
         "от пользователей." });
      lines += ({ "\tautoload\tУстановите 1, если вы хотите сохранять вашу экипировку " +
         "при выходе из игры." });
      lines += ({ "\tsave_on_quit\tУстановите 1, если вы хотите зайти в игру в том " +
         "же месте в котором выходите." });
      lines += ({ "\tquit_message\tУстанавливает сообщение при выходе.  " +
         "Пример: $N $vquit." });
      lines += ({ "\tdebug_commands\tУстановите 1, если вы хотите видеть отладочную " +
         "информацию по командам." });
      lines += ({ "\tverbose_errors\tУстановите 1, если вам нужны более длинные " +
         "коды ошибок." });
      lines += ({ "\tdisplay_caught\tУстановите 1, если хотите видеть обнаруженные " +
         "runtime-ошибки." });
   }
   lines += ({ " " });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tнастройки width 50" });
   lines += ({ "\tнастройки email foo@bar.com" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "ansi");
   add_also("player", "wimpy");
}

void list_vars(void) {
   string name, *names;
   int i;

   names = ({ "height", "width", "prompt" });
   if (!query_guest(this_player()->query_name() ) ) {
      names += ({ "realname", "email", "website" });
      }
   if (query_wizard(this_player() ) ) {
      names += ({ "start_room", "hidden", "autoload", "save_on_quit", 
         "quit_message", "debug_commands", "verbose_errors",
         "display_caught" });
   }
   for (i = 0; i < sizeof(names); i++) {
      out_unmod(names[i] + "=" + call_other(this_player(), "query_" +
         names[i]) + "\n");
   }
}

static void main(string str) {
   string name, value;
   int i;

   if (!alsos) {
      setup_alsos();
   }

   if (empty_str(str)) {
      list_vars();
   } else if (sscanf(str, "-%s", str)) {
      this_player()->more(usage());
      return;
   } else if ((sscanf(str, "%s %s", name, value) != 2) &&
      (sscanf(str, "%s=%s", name, value) != 2)) {
      this_player()->more(usage());
      return;
   } else {
        if (value == "on") {
           value = "1";
        } else if (value == "off") {
           value = "0";
         }
        switch(name) {
           case "height":
           case "width":
           case "prompt":
              break;
           case "realname":
           case "email":
           case "website":
              if (query_guest(this_player()->query_name() ) ) {
                 write("Вы должны быть в игре игровым персонажем.");
              return;
              }
              break;
           case "hidden":
           case "autoload":
           case "save_on_quit":
           case "debug_commands":
           case "verbose_errors":
           case "display_caught":
              if (value != "0" && value != "1") {
                 write("Параметр для " + name + " должен быть 1 или 0.");
                 return;
              }
           case "quit_message":
           case "start_room":
              if (query_wizard(this_player() ) )  {
                 break;
              }
           default:
              write("Неправильное название настройки \"" + name + "\".\n\n");
              this_player()->more(usage());
              return;
        }
      write("Ok.");
      if (str2val(value) != -1) {                     
         /* We've got a value */
         call_other(this_player(), "set_" + name, str2val(value) );
      } else {
         call_other(this_player(), "set_" + name, value);
      }
   }
}
