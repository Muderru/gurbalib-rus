/* search.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: искать [-h] [ПРЕДМЕТ]" });
   lines += ({ "" });
   lines += ({ "Искать указанный объект." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tискать хлам" });
   lines += ({ "\tискать" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "buy");
   add_also("player", "extinguish");
   add_also("player", "identify");
   add_also("player", "light");
   add_also("player", "list");
   add_also("player", "listen");
   add_also("player", "look");
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
   object obj;

   if (!alsos) {
      setup_alsos();
   }

   if (sscanf(str, "-%s", str)) {
      this_player()->more(usage());
      return;
   }

   if (this_environment()->is_dark()) {
      if (query_wizard(this_player())) {
         write("Хотя в комнате темно, так как вы администратор " +
            "вы можете видеть во тьме.\n");
      } else if (this_player()->query_race_object()->has_darkvision()) {
         write("Хотя в комнате темно, ваша раса позволяет вам " +
            "видеть в темноте.\n");
      } else {
         write("Тут слишком темно.\n");
         return;
      }
   }

   if (!str || str == "" || strcmp(str, "room") == 0) {
      obj = this_player()->query_environment();
   } else {
      obj = this_player()->present(str);
      if (!obj) {
         obj = this_player()->query_environment()->present(str);
      }
   }

   if (obj->is_living()) {
      write("Это не прилично.");
      return;
   }

   if (!call_other(obj, "do_search")) {
      this_player()->query_environment()->tell_room(this_player(),
         this_player()->query_Name() + " ищет " + 
         obj->query_id() + "\n");
      write("Вы ничего не нашли.\n");
   }
}
