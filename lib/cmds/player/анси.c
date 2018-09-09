/* ansi.c */
inherit M_COMMAND;

string parse_error;

string *usage(void) {
   string mode, *lines;

   if (this_player()->query_ansi() == 1) {
      mode = "вкл";
   } else {
      mode = "выкл";
   }

   lines = ({ "Использование: анси [-h] [вкл|выкл|показать]" });
   lines += ({ "" });
   lines += ({ "Используется для включения или выключения цветов, также может показать текущие настройки." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "\tвкл\tВключает поддержку ANSI." });
   lines += ({ "\tвыкл\tВыключает поддержку ANSI." });
   lines += ({ "\tпоказать\tПоказывает текущие настройки ANSI." });
   lines += ({ "Примеры:" });
   lines += ({ "\tанси вкл" });
   lines += ({ "\tанси показать" });

   lines += get_alsos();

   lines += ({ "" });
   lines += ({ "В данный момент ваш режим ANSI: " + mode });

   return lines;
}

setup_alsos() {
   add_also("player", "alias");
   add_also("player", "clear");
   add_also("player", "describe");
   add_also("player", "ignore");
   add_also("player", "passwd");

   add_also("admin", "coloradm");
}

#define GRAMMAR "whitespace=/[ ]+/\n" + \
                "TAG=/[A-Z_][A-Z0-9_]*/ \n" + \
                "TAG=/NIL/\n" + \
                "args: tags ? collect_map\n" + \
                "assign: tag '=' values ? wrap_assign\n" + \
                "tags: assign\n" + \
                "tags: tags assign\n" + \
                "tags: tags ',' assign\n" + \
                "tags: tags 'and' assign\n" + \
                "tag: TAG ? valid_tag_name\n" + \
                "values: value_list\n" + \
                "value_list: value\n" + \
                "value_list: value_list '+' value\n" + \
                "value: TAG ? valid_value\n"

/*
 * If the arg[0] is a base symbol, it can't be used
 * as a custom tag.
 */
mixed *valid_tag_name(mixed * arg) {
   if (ANSI_D->query_custom_symbol(arg[0])) {
      return arg;
   } else {
      parse_error = "Неправильная метка: " + arg[0];
      return nil;
   }
}

mixed *valid_value(mixed * arg) {
   if ((arg[0] == "NIL") || ANSI_D->query_any_symbol(arg[0])) {
      return arg;
   } else {
      parse_error = "Неправильное значение: " + arg[0];
      return nil;
   }
}

mixed *wrap_assign(mixed * arg) {
   return ( { ([arg[0]:(arg[2..] - ( { "+" } ))]) } );
}

mixed *collect_map(mixed * arg) {
   int i, sz;
   mapping result;

   result = ([]);

   for (i = 0, sz = sizeof(arg); i < sz; i++) {
      if (mappingp(arg[i])) {
         result += arg[i];
      }
   }
   return ( { result } );
}

void set_colors(mixed *args) {
   int i, sz;
   string *symbols;

   if (!arrayp(args) || !mappingp(args[0])) {
      write("Извините, но это непонятно.\n" +
         "Попробуйте что-то типа 'color symbol = ATTRIBUTE + COLOR'\n" +
         "                   или 'color symbol = COLOR, symbol = COLOR'\n" +
         "Помните, что использование имени предопределенного цвета в качестве символа " +
         "не разрешено, но использовать символы как цвета можно, например\n" +
         " 'color room_desc = room_exit' будет работать\n\n" +
         "Правильные цвета и символы:\n\n");
         "/cmds/player/ansi"->main("show");
   } else {
      symbols = map_indices(args[0]);
      sz = sizeof(symbols);
      for (i = 0; i < sz; i++) {
         /* special case, 'NIL' tag means remove this symbol.
            also note this is a string, not the nil value */
         if (args[0][symbols[i]][0] == "NIL") {
            this_player()->set_custom_color(symbols[i], nil);
         } else {
            this_player()->set_custom_color(symbols[i],
               args[0][symbols[i]]);
         }
      }
   }
}

static void main(string str) {
   mixed *args;
   string error;
   int i, pos;

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

   if ((str == "вкл") || (str == "Вкл") || (str == "1")) {
      this_player()->set_ansi(1);
      out("ANSI включено.\n");
   } else if ((str == "выкл") || (str == "Выкл") || (str == "0")) {
      this_player()->set_ansi(0);
      out("ANSI выключено.\n");
   } else if ((str == "показать") || (str == "показ")) {
      out(ANSI_D->color_table());
   } else {
      str = uppercase(str);

      parse_error = nil;
      error = catch(args = parse_string(GRAMMAR, str));

      if (parse_error) {
         write(parse_error);
      } else {
         if (error) {
            if (sscanf(error, "Плохой токен при смещении %d", pos) == 1) {
               write("Неправильный символ " + str[pos..pos] + ".");
               return;
            } else {
               rethrow();
            }
         }

         set_colors(args);
      }
   }
}

