/* remove.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: снять [-h] [все|OBJ]" });
   lines += ({ "" });
   lines += ({ "Позволяет вам снять указанный предмет OBJ, который на вас " +
      "надет или которым вы вооружены." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "\tвсе\tРаздеться до гола." });
   lines += ({ "Примеры:" });
   lines += ({ "\tснять шлем" });
   lines += ({ "\tснять все" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "get");
   add_also("player", "drop");
   add_also("player", "put");
   add_also("player", "wear");
   add_also("player", "wield");
}

static void do_remove(object obj, int loud) {
   string slot;
   object worn;
   int wielded;

   if (!obj) {
      if (loud) {
         write("Что вы хотите снять?");
      }
      return;
   }

   if (obj->is_worn()) {
      if (obj->is_cursed()) {
         if (loud) {
            this_player()->targeted_action(
               "$N пытается снять" + obj->query_obj_i_name() + ", но неудачно.", nil, obj);
            write("Странно... Это не снимается.\n");
         }
         return;
      }
   } else if (obj->is_wielded()) {
      wielded = 1;
      if (obj->is_cursed()) {
         if (loud) {
            this_player()->targeted_action(
               "$N пытается снять" + obj->query_obj_i_name() + ", но неудачно.", nil, obj);
            write("Странно... Это не снимается.\n");
         }
         return;
      }
   } else {
      if (loud) {
         write("На вас это не одето или вы не вооружены этим.\n");
      }
      return;
   }

  if (wielded) {
      this_player()->do_unwield(obj);
      this_player()->targeted_action(obj->query_unwield_message(), nil, obj);
      obj->after_unwield(this_player(), "снять");
   } else {
      this_player()->do_remove(obj);
      this_player()->targeted_action(obj->query_remove_message(), nil, obj);
      obj->after_unwear(this_player(), "снять");
   }
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

   if (str == "все") {
      inv = this_player()->query_inventory();
      max = sizeof(inv);
      for (i = 0; i < max; i++) {
         do_remove(inv[i], 0);
      }
      return;
   }

   obj = this_player()->present(lowercase(str));
   do_remove(obj, 1);
}
