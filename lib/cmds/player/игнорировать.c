/* ignore.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: игнорировать [-h] [PLAYER]" });
   lines += ({ "" });
   lines += ({ "Позволяет вам игнорировать игрока PLAYER " });
   lines += ({ "или прекращает его игнорирование." });
   lines += ({ "Если игрок не указан, то показывает список игроков в игноре." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tигнорировать туор" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "alias");
   add_also("player", "ansi");
   add_also("player", "clear");
   add_also("player", "describe");
   add_also("player", "passwd");

   add_also("admin", "coloradm");
}

/* Add a user to your ignore list  -- Arron Cusimano (mordain) 20090321 */
static void main(string arg) {
   string out;
   int i, sz;
   string *list;

   if (!alsos) {
      setup_alsos();
   }

   if (empty_str(arg)) {
      out = "Список игнорируемых:\n";
      list = this_player()->query_ignored_all();
      for (i = 0, sz = sizeof(list); i < sz; ++i) {
         out += list[i] + "\n";
      }
      write(out);
      /*write(dump_value(this_player()->query_ignored_all(), ([]))); */
      return;
   }
   if (sscanf(arg, "-%s", arg)) {
      this_player()->more(usage());
      return;
   }
   if (this_player()->query_ignored(arg)) {
      write("Удалить - " + arg + "\n");
      this_player()->remove_ignore(arg);
      return;
   }
   write("Игнорировать - " + arg + "\n");
   this_player()->add_ignore(arg);
}
