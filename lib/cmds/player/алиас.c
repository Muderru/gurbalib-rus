/* alias.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: алиас [-h] [ALIAS COMMAND]" });
   lines += ({ "" });
   lines += ({ "Позволяет вам создавать алиасы для команд." });
   lines += ({ "Если не указан алиас, то показывает список ваших текущих алиасов." });
   lines += ({ "Если не указана команда, то удаляет указанный алиас." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "\t-r\tУдаляет указанный алиас." });
   lines += ({ "Примеры:" });
   lines += ({ "\tалиас ga get all" });
   lines += ({ "\tалиас da drop all" });
   lines += ({ "\tалиас da" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "ansi");
   add_also("player", "clear");
   add_also("player", "describe");
   add_also("player", "ignore");
   add_also("player", "passwd");

   add_also("admin", "cmdadm");
   add_also("admin", "coloradm");
   add_also("admin", "rehash");
}

void show_aliases(void) {
   mapping alias;
   string *aliases, *lines;
   int i;

   alias = this_player()->query_aliases();
   aliases = map_indices(alias);

   lines = ({ "Вы определили следующие алиасы: " });
   if (sizeof(aliases) == 0) {
      lines += ({ "   У вас нет персональных определенных алиасов." });
      lines += ALIAS_D->show_alias("", "");
      this_player()->more(lines);
      return;
   }

   lines = ({ "Вы определили следующие алиасы: " });
   for (i = 0; i < sizeof(aliases); i++) {
      lines += ({ "  " + aliases[i] + "='" + alias[aliases[i]] + "'" });
   }

   lines += ALIAS_D->show_alias("", "");
   this_player()->more(lines);
}

static void main(string str) {
   string cmd, arg;

   if (!alsos) {
      setup_alsos();
   }

   if (empty_str(str)) {
      show_aliases();
      return;
   }

   if (sscanf(str, "-%s", str)) {
      this_player()->more(usage());
      return;
   } else {
      if (sscanf(str, "%s %s", cmd, arg) != 2) {
         /* Remove an alias */
         if (this_player()->is_alias(str)) {
            write("Алиас '" + str + "' (" + 
                  this_player()->query_alias(str) + ") удален.");
            this_player()->remove_alias(str);
            return;
         }

         this_player()->more(usage());
         return;
      }

      /* Check for invalid input */
      if ((cmd == " ") || (arg == " ") || (cmd == "") || (arg == "")) {
         this_player()->more(usage());
         return;
      }

      this_player()->add_alias(cmd, arg);
      write("Алиас '" + cmd + "' (" + arg + ") добавлен.");
   }
}
