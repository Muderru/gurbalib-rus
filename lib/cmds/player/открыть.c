/* open.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: открыть [-h] [все|OBJ]" });
   lines += ({ "" });
   lines += ({ "Позволяет вам открыть выбранный предмет OBJ." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "\tвсе\tОткрывает все, что только можно открыть." });
   lines += ({ "Примеры:" });
   lines += ({ "\tоткрыть сундук" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "close");
}

static void do_open(object obj, int loud) {
   string slot;
   object worn;

   if (!obj) {
         if (loud) { 
         write("Что вы пытаетесь открыть?");
      }
      return;
   }

   if (!obj->is_openable()) {
      if (loud) {
         write("Вы не можете открыть " + obj->query_obj_i_name() + ".");
      }
      return;
   }
   obj->do_open(this_player());
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

   if (str == "all") {
      inv = this_player()->query_environment()->query_inventory();
      max = sizeof(inv);
      for (i = 0; i < max; i++) {
         do_open(inv[i], 0);
      }

      inv = this_player()->query_inventory();
      max = sizeof(inv);
      for (i = 0; i < max; i++) {
         do_open(inv[i], 0);
      }
      return;
   }

   obj = this_player()->query_environment();
   if (obj->do_open(str)) {
      return;
   }

   obj = this_player()->present(str);
   if (!obj) {
      obj = this_player()->query_environment()->present(str);
   }
   do_open(obj, 1);
}
