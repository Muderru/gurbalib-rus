/* eat.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: есть [-h] [OBJECT]" });
   lines += ({ "" });
   lines += ({ "Поглощение выбранного объекта." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tесть яброко" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "attack");
   add_also("player", "cast");
   add_also("player", "enter");
   add_also("player", "follow");
   add_also("player", "go");
   add_also("player", "pray");
   add_also("player", "query");
   add_also("player", "quit");
   add_also("player", "wimpy");
}

static void main(string str) {
   object obj;

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
      write("Что вы хотите съесть?\n");
      return;
   }

   if (!obj->is_eatable()) {
      write("Вы не можете съесть это.\n");
      return;
   }

   call_other(obj, "do_eat");
}
