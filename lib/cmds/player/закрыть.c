/* close.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: закрыть [-h] [all|OBJ]" });
   lines += ({ "" });
   lines += ({ "Позволяет вам закрыть указанный предмет OBJ." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "\tвсе\tЗакрывает все, что только можно закрыть." });
   lines += ({ "Примеры:" });
   lines += ({ "\tзакрыть сундук" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "open");
}

static void do_close(object obj, int loud) {
   string slot;
   object worn;

   if (!obj) {
      if (loud) {
         write("Что вы хотите закрыть?");
      }
      return;
   }

   if (!obj->is_closable()) {
      if (loud) {
         write("Вы не можете закрыть " + obj->query_obj_i_name() + ".");
      }
      return;
   }
   obj->do_close(this_player());
}

static void main(string str) {
   object obj, *inv;
   int i, max;

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

   str = lowercase(str);

   if (str == "все") {
      inv = this_player()->query_environment()->query_inventory();
      max = sizeof(inv);
      for (i = 0; i < max; i++) {
         do_close(inv[i], 0);
      }

      inv = this_player()->query_inventory();
      max = sizeof(inv);
      for (i = 0; i < max; i++) {
         do_close(inv[i], 0);
      }
      return;
   }

   obj = this_player()->query_environment();
   if (obj->do_close(str)) {
      return;
   }

   obj = this_player()->present(str);
   if (!obj) {
      obj = this_player()->query_environment()->present(str);
   }
   do_close(obj, 1);
}
