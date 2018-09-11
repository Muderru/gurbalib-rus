/* identify.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: опознать [-h] OBJ" });
   lines += ({ "" });
   lines += ({ "Позволяет определить скрытые свойства OBJ, если они есть " +
      "конечно." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tопознать меч" });
   lines += ({ "\tопознать шлем" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "buy");
   add_also("player", "extinguish");
   add_also("player", "light");
   add_also("player", "list");
   add_also("player", "listen");
   add_also("player", "look");
   add_also("player", "search");
   add_also("player", "sell");
   add_also("player", "value");

   add_also("wiz", "last");
   add_also("wiz", "locate");
   add_also("wiz", "mudlist");
   add_also("wiz", "possess");
   add_also("wiz", "rwho");
   add_also("wiz", "snoop");
   add_also("wiz", "where");
   add_also("wiz", "who");
}

static void main(string str) {
   object obj, *wielded;

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

   obj = this_player()->present(lowercase(str));
   if (!obj) {
      write("У вас этого нет?");
      return;
   }

   if (obj->query_detailed_desc()) {
      write(obj->query_detailed_desc());
   } else {
      write("Вы не определили ничего необычного.");
   }
}
