/* say.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: говорить [-h] MSG" });
   lines += ({ "" });
   lines += ({ "Сказать всем в комнате сообщение MSG." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tговорить Я устал, я ухожу." });
   lines += ({ "\tговорить нет, не вы!" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "bug");
   add_also("player", "chan");
   add_also("player", "emote");
   add_also("player", "rsay");
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

string *get_strtype(string me, string you, string str) {
      switch (str[strlen(str) - 1]) {
         case '?':
            me = " спрашиваете: ";
            you = " спрашивает: ";
            break;
         case '@':
            me = " гордо восклицаете: ";
            you = " гордо восклицает: ";
            str = str[..strlen(str) - 2];
            break;
         case '#':
            me = " хвастаетесь: ";
            you = " хвастается: ";
            str = str[..strlen(str) - 2];
            break;
         case '$':
            me = " говорите с сарказмом: ";
            you = " говорит с сарказмом: ";
            str = str[..strlen(str) - 2];
            break;
         case '%':
            me = " задумчиво говорите: ";
            you = " задумчиво говорит: ";
            str = str[..strlen(str) - 2];
            break;
         case '^':
            me = " говорите с восхищением: ";
            you = " говорит с восхищением: ";
            str = str[..strlen(str) - 2];
            break;
         case '&':
            me = " говорите с насмешкой: ";
            you = " говорите с насмешкой: ";
            str = str[..strlen(str) - 2];
            break;
         case '*':
            me = " огрызаетесь: ";
            you = " огрызается: ";
            str = str[..strlen(str) - 2];
            break;
         case '/':
            me = " говорите на повышенных тонах: ";
            you = " говорит на повышенных тонах: ";
            str = str[..strlen(str) - 2];
            break;
         case '+':
            me = " громко говорите: ";
            you = " громко говорит: ";
            str = str[..strlen(str) - 2];
            break;
         case '-':
            me = " шепчите: ";
            you = " шепчет: ";
            str = str[..strlen(str) - 2];
            break;
         case '=':
            me = " поправляете: ";
            you = " поправляет: ";
            str = str[..strlen(str) - 2];
            break;
         case '~':
            me = " пробалтываетесь: ";
            you = " пробалтывается: ";
            str = str[..strlen(str) - 2];
            break;
         case ';':
            me = " говорите мягко: ";
            you = " говорит мягко: ";
            str = str[..strlen(str) - 2];
            break;
         case ':':
            me = " бормочите: ";
            you = " бормочит: ";
            str = str[..strlen(str) - 2];
            break;
         case '|':
            me = " отвечаете: ";
            you = " отвечает: ";
            str = str[..strlen(str) - 2];
            break;
         case '>':
            me = " уверенно говорите: ";
            you = " уверенно говорит: ";
            str = str[..strlen(str) - 2];
            break;
         case '\{':
            me = " говорите, брызгая слюной: ";
            you = " говорит, брызгая слюной: ";
            str = str[..strlen(str) - 2];
            break;
         case '\]':
            me = " шутите: ";
            you = " шутит: ";
            str = str[..strlen(str) - 2];
            break;
         case '\}':
            me = " говорите с трудом: ";
            you = " говорит с трудом: ";
            str = str[..strlen(str) - 2];
            break;
         case '\\':
            me = " говорите упавшим голосом: ";
            you = " говорит упавшим голосом: ";
            str = str[..strlen(str) - 2];
            break;
         case '`':
            me = " комментируете: ";
            you = " комментирует: ";
            str = str[..strlen(str) - 2];
            break;
         case '\[':
            me = " говорите со смехом: ";
            you = " говорит со смехом: ";
            str = str[..strlen(str) - 2];
            break;
         case '<':
            me = " говорите, указывая на себя: ";
            you = " говорит, указывая на себя: ";
            str = str[..strlen(str) - 2];
            break;
         case '_':
            me = " говорите с придыханием: ";
            you = " говорит с придыханием: ";
            str = str[..strlen(str) - 2];
            break;
      }
      return ({me, you, str});
}

/* Ok so it isn't the best method in the world for making sure that you 
   get the correct conjugation, but it works.*/
static void main(string str) {
   int i;
   string me;         /*what I, the one who's talking, sees */
   string you;        /*what all the others in the room sees */

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

   /* Strip trailing whitespaces */

   if (!this_environment()) {
      write("Тут не подходящее окружение " +
         "для разговоров.");
      return;
   }

   for (i = strlen(str) - 1; i > 0; i--) {
      if (str[i] != ' ') {
         break;
      }
      str = str[0..(i - 1)];
   }

   /*default values */
   me = " говорите: ";
   you = " говорит: ";

   if (str != "") {
      if ((str[strlen(str) - 1]) == '!') {
         me = " говорите взволнованно: ";
         you = " говорит взволнованно: ";
         if ((str[strlen(str) - 2]) == '!') {
            if ((str[strlen(str) - 3]) == '!') {
               me = " кричите: ";
               you = " кричит: ";
            } else {
               me = " вопите: ";
               you = " вопит: ";
            }
         }
      }

      if ((str[strlen(str) - 1]) == '.') {
         if ((str[strlen(str) - 2]) == '.') {
            if ((str[strlen(str) - 3]) == '.') {
               me = " замолкаете: ";
               you = " замолкает: ";
            }
         }
      }

      ({me, you, str}) = get_strtype(me, you, str);

      switch (str[strlen(str) - 1]) {
         case '.':
         case '?':
         case '!':
         case ',':
            break;
         default:
            str += ".";
            break;
      }

      if (this_player()->query_Name()) {
         this_environment()->tell_room(this_player(),
            "%^GREEN%^" + capitalize(this_player()->query_Name()) + you +
            "%^RESET%^" + capitalize(str) + "\n");
      } else {
         this_environment()->tell_room(this_player(),
            "%^GREEN%^" + this_player()->query_i_name() + you +
            "%^RESET%^" + capitalize(str) + "\n");
      }
      this_player()->message("%^GREEN%^You" + me + "%^RESET%^" +
         capitalize(str) + "\n", 1);
   } else {
      write("Говорить что?\n");
   }
}
