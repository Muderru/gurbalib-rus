/* put.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: положить [-h] [все|OBJ] [в|на] OBJ2" });
   lines += ({ "" });
   lines += ({ "Позволяет вам поместить OBJ внутрь OBJ2." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "\tвсе\tПоложить все, что у вас есть, внутрь OBJ2." });
   lines += ({ "Примеры:" });
   lines += ({ "\tположить меч в сундук" });
   lines += ({ "\tположить все в сундук" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "get");
   add_also("player", "drop");
   add_also("player", "remove");
   add_also("player", "wear");
   add_also("player", "wield");
}

static void do_put(object obj1, object obj2, int loud) {
   string slot;
   object worn;

   if (!obj1) {
      if (loud) {
         write("Что и куда вы пытаетесь положить?");
      }
      return;
   }

   if (!obj2) {
      if (loud) {
         write("Куда вы пытаетесь положить это?\n");
      }
      return;
   }

   if (!obj2->is_container()) {
      if (loud) {
         write("Вы не можете положить это здесь.\n");
      }
      return;
   }

   if (obj2->is_closed()) {
      if (loud) {
         write("Закрыто.\n");
      }
      return;
   }

   if (obj2 == this_player()) {
      if (loud) {
         write("Вы не можете положить что-то в ваш инвентарь, используйте 'взять' вместо этого.\n");
      }
      return;
   }

   if (obj1->is_worn()) {
      if (obj1->is_cursed()) {
         this_player()->targeted_action("$N пытается снять" + obj1->query_obj_i_name() + ", но неудачно.",
            nil, obj1);
         write("Странно... Это не снимается.\n");
         return;
      } else {
         this_player()->do_remove(obj1);
         this_player()->targeted_action(obj1->query_remove_message(), 
            nil, obj1);
      }
   }

   if (obj1->is_wielded()) {
      if (obj1->is_cursed()) {
         this_player()->targeted_action("$N пытается снять" + obj1->query_obj_i_name() +
            ", но неудачно.", nil, obj1);
         write("Странно... Это не снимается.\n");
         return;
      } else {
         this_player()->do_unwield(obj1);
         this_player()->targeted_action(obj1->query_unwield_message(), 
            nil, obj1);
      }
   }

   if (obj1->move(obj2)) {
     if (this_player()->query_gender() == "male") {
      this_player()->targeted_action("$N положил " + obj1->query_obj_i_name() + " в " + obj2->query_obj_i_name() + ".", nil, obj1, obj2);
   } else if (this_player()->query_gender() == "female") {
      this_player()->targeted_action("$N положила " + obj1->query_obj_i_name() + " в " + obj2->query_obj_i_name() + ".", nil, obj1, obj2);
   } else {
      this_player()->targeted_action("$N положило " + obj1->query_obj_i_name() + " в " + obj2->query_obj_i_name() + ".", nil, obj1, obj2);
   }         
        obj2->after_move(this_player(), obj1);
   } else {
      this_player()->targeted_action("$N пытается положить " + obj1->query_obj_i_name() + " в " + obj2->query_obj_i_name() +
         ", но там нет места.", nil, obj1, obj2);
   }
}

static void main(string str) {
   object obj, obj2;
   object *inv;
   int i, max;
   string what, where;

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

   if (sscanf(str, "%s в %s", what, where) == 2) {
   } else if (sscanf(str, "%s на %s", what, where) == 2) {
   } else if (sscanf(str, "%s %s", what, where) == 2) {
   } else {
      write("Что и куда вы хотите положить?");
      return;
   }

   obj = this_player()->present(lowercase(where));
   if (!obj) {
      obj = this_player()->query_environment()->present(lowercase(where));
   }
   if (!obj) {
      write("Куда вы хотите положить это?");
      return;
   }

   if (what == "все") {
      if (obj->is_closed()) {
         write("Закрыто.\n");
         return;
      }

      inv = this_player()->query_inventory();
      max = sizeof(inv);
      for (i = 0; i < max; i++) {
         do_put(inv[i], obj, 0);
      }
      return;
   }

   obj2 = this_player()->present(lowercase(what));
   if (!obj2) {
      obj2 = this_player()->query_environment()->present(lowercase(what));
   }
   do_put(obj2, obj, 1);
}
