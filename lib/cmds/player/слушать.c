/* listen.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: слушать [-h] [ПРЕДМЕТ]" });
   lines += ({ "" });
   lines += ({ "Позволяет вам прислушаться к указанному предмету." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tслушать дверь" });
   lines += ({ "\tслушать" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "buy");
   add_also("player", "extinguish");
   add_also("player", "identify");
   add_also("player", "light");
   add_also("player", "list");
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
   object obj;

   if (!alsos) {
      setup_alsos();
   }

   if (sscanf(str, "-%s", str)) {
      this_player()->more(usage());
      return;
   }

   if (!str || str == "" || strcmp(str, "комната") || strcmp(str, "комнату") == 0) {
      obj = this_player()->query_environment();
   } else {
      obj = this_player()->present(str);
      if (!obj) {
         obj = this_player()->query_environment()->present(str);
      }
   }

   if (!obj) {
      write("Что слушать?\n");
      return;
   }

   if (!call_other(obj, "do_listen")) {
     if (this_player()->query_gender() == "male") {
      this_player()->query_environment()->tell_room(this_player(),
         this_player()->query_Name() + " остановился прислушиваясь к " + 
         obj->query_obj_d_name() + ".\n");
   } else if (this_player()->query_gender() == "female") {
      this_player()->query_environment()->tell_room(this_player(),
         this_player()->query_Name() + " остановилась прислушиваясь к " + 
         obj->query_obj_d_name() + ".\n");
   } else {
      this_player()->query_environment()->tell_room(this_player(),
         this_player()->query_Name() + " остановилось прислушиваясь к " + 
         obj->query_obj_d_name() + ".\n");
   }         
      write("Вы ничего не услышали.\n");
   }
}
