/* look.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: смотреть [-h] [[на|в] OBJ]" });
   lines += ({ " " });
   lines += ({ "Позволяет вам получить больше информации по указанному объекту OBJ." });
   lines += ({ "Если не указаны аргументы, то вы получаете информацию о вашем окружении." });
   lines += ({ " " });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tсмотреть" });
   lines += ({ "\tсмотреть на дерево" });
   lines += ({ "\tсмотреть в сундук" });

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

static void do_look_liv(object obj) {
   int i, flag;
   object *objs;

   this_environment()->tell_room(this_player(), this_player()->query_Name() +
      " рассматривает " + capitalize(obj->query_id()) + ".\n");

   write("%^PLAYER%^" + obj->query_short() + "%^RESET%^\n");

   write(obj->query_long());
     if (obj->query_gender() == "male") {
        write("Это " + obj->query_race() + " мужского пола, " +
         " который " + obj->query_status() + ".\n");
   } else if (obj->query_gender() == "female") {
        write("Это " + obj->query_race() + " женского пола, " +
         " которая " + obj->query_status() + ".\n");
   } else {
        write("Это " + obj->query_race() + " неопределенного пола, " +
         " которое " + obj->query_status() + ".\n");
   }

   flag = 0;
   objs = obj->query_inventory();

   if (obj->query_gender() == "male") {
      write(" \nОн использует:\n");
   } else if (obj->query_gender() == "female") {
      write(" \nОна использует:\n");
   } else {
      write(" \nОно использует:\n");
   }

   for (i = 0; i < sizeof(objs); i++) {
      if (objs[i]->is_worn()) {
         write("  " + objs[i]->query_short() + " %^CYAN%^[" +
            objs[i]->query_wear_position() + "]%^RESET%^\n");
         flag = 1;
      } else if (objs[i]->is_wielded()) {
         write("  " + objs[i]->query_short() + " %^CYAN%^[" +
            objs[i]->query_wield_position() + "]%^RESET%^\n");
         flag = 1;
      }
   }
   if (flag == 0) {
      write("  Ничего.");
   }
}

static void main(string str) {
   string what;
   object obj;

   if (!alsos) {
      setup_alsos();
   }

   if (empty_str(str)) {
      obj = this_environment();
   } else {

      if (sscanf(str, "-%s", str)) {
         this_player()->more(usage());
         return;
      }

      if (sscanf(str, "в %s", what) == 1) {
      } else if (sscanf(str, "на %s", what) == 1) {
      } else {
         what = str;
      }

      if (member_array(what, this_environment()->query_items() ) > -1) {
         this_environment()->tell_room(this_player(), 
            this_player()->query_Name( ) + " смотрит на " + 
            lowercase(what) + ".\n");
         write(this_environment()->query_item(what));
         return;
      }

      obj = this_player()->present(lowercase(what));
      if (!obj) {
         obj = this_environment()->present(lowercase(what));
      }
   } 

   if (!obj) {
      write("Смотреть на кого?");
      return;
   }

   this_player()->do_look(obj);
}
