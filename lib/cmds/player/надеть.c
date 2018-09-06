/* wear.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: надеть [-h] [все|OBJ]" });
   lines += ({ "" });
   lines += ({ "Позволяет вам надеть выбранный OBJ." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "\tвсе\tНадевает все возможные предметы." });
   lines += ({ "Примеры:" });
   lines += ({ "\tнадеть шлем" });
   lines += ({ "\tнадеть штаны" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "get");
   add_also("player", "drop");
   add_also("player", "put");
   add_also("player", "remove");
   add_also("player", "wield");
}

int do_wear(object obj, int loud) {
   string slot;
   object worn;

   if (!obj) {
      if (loud) {
         write("Что вы пытаетесь надеть?");
      }
      return 0;
   }

   if (!obj->is_wearable()) {
      if (loud) {
         write("Вы не можете надеть это.");
      }
      return 0;
   }
   if (obj->query_worn() == 1) {
      if (loud) {
         write(obj->query_obj_i_name() + " уже на вас.");
      }
      return 0;
   }

   slot = obj->query_slot();
   if (!obj->query_valid_slot(slot)) {
      if (loud) {
         write("На вас нет свободного места, чтобы надеть это.\n");
      }
      return 0;
   }

   worn = this_player()->query_slot(slot);
   if (worn && (slot != "apparel")) {
      if (loud) {
       if (worn->query_obj_gender() == "male") {
         write("На вас уже надет " + worn->query_obj_i_name() + ".");
   }   else if (worn->query_obj_gender() == "female") {
         write("На вас уже надета " + worn->query_obj_i_name() + ".");
   }   else {
         write("На вас уже надето " + worn->query_obj_i_name() + ".");
   }
           }
      return 0;
   }

   this_player()->do_wear(obj);
   this_player()->targeted_action(obj->query_wear_message(), nil, obj);
      obj->after_wear(this_player());
   return 1;
}

static void main(string str) {
   object obj, *inv;
   int i, max, done;

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
      write("Вы не можете сделать это, пока находитесь в царстве мертвых.\n");
      return;
   }

   if (str == "все") {
      inv = this_player()->query_inventory();
      max = sizeof(inv);
      done = 0;
      for (i = 0; i < max; i++) {
         if (inv[i]->wear_hook(this_player())) {
            if (do_wear(inv[i], 0)) {
               done = 1;
            }
         }
      }
      if (!done) {
         write("Вам нечего надевать.\n");
      }
      return;
   }

   obj = this_player()->present(lowercase(str));
   if (obj->wear_hook(this_player())) {
      do_wear(obj, 1);
   }
}

