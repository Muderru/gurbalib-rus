/* wield.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: вооружиться [-h] [все|obj]" });
   lines += ({ "" });
   lines += ({ "Позволяет вам вооружиться выбранным объектом OBJ." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "\tвсе\tВооружиться всеми возможными предметами.." });
   lines += ({ "Примеры:" });
   lines += ({ "\tвооружиться меч" });
   lines += ({ "\tвооружиться топор" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "get");
   add_also("player", "drop");
   add_also("player", "put");
   add_also("player", "remove");
   add_also("player", "wear");
}

static int do_wield(object obj, int loud) {
   string slot;
   object *wielded;

   if (!obj) {
      if (loud) {
         write("Может быть вам сначала это поднять?");
      }
      return 0;
   }

   if (!obj->is_wieldable()) {
      if (loud) {
         write("Вы не можете вооружиться этим.");
      }
      return 0;
   }

   if (obj->query_wielded() == 1) {
      if (loud) {
         write("Вы уже вооружены этим.");
      }
      return 0;
   }

   wielded = this_player()->query_wielded();

   if (obj->query_wield_type() == "single") {
      if (sizeof(wielded) >= 2) {
         write("Ваши руки заняты.");
         return 0;
      }
   } else {
      if (sizeof(wielded) != 0) {
         write("Вы уже вооружены чем-то.");
         return 0;
      }
   }

   this_player()->do_wield(obj);
   this_player()->targeted_action(obj->query_wield_message(), nil, obj);
      obj->after_wield(this_player());
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
         if (inv[i]->wield_hook(this_player())) {
            if (do_wield(inv[i], 0)) {
               done = 1;
            }
         }
      }

      if (!done) {
         write("У вас нет ничего, чем бы можно было вооружиться.\n");
      }
      return;
   }

   obj = this_player()->present(lowercase(str));
   if (!obj) {
      write("Вооружиться чем?");
      return;
   }
   if (obj->wield_hook(this_player())) {
      do_wield(obj, 1);
   }
}
