/* show.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: показать [-h] [все|OBJ] PLAYER" });
   lines += ({ "" });
   lines += ({ "Позволяет вам показать предмет OBJ другому игроку." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tпоказать меч туор" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "get");
   add_also("player", "give");
   add_also("player", "drop");
}

static void display_object(object who, object what) {
   object *objs;
   int x, maxx;

   if (this_environment()->is_dark()) {
      if (query_wizard(this_player())) {
         who->message("Хотя в комнате темно, так как вы администратор " +
            "вы можете видеть во тьме.\n");
      } else if (this_player()->query_race_object()->has_darkvision()) {
         who->message("Хотя в комнате темно, ваша раса позволяет вам " +
            "видеть в темноте.\n");
      } else {
         who->message("Тут слишком темно.\n");
         return;
      }
   }

   this_environment()->event("body_look_at", who, what);
   
   who->message(what->query_long());

   if (what->is_closed()) {
      who->message("Закрыто.");
   } else if (what->is_container()) {
      objs = what->query_inventory();
      who->message(" \nСодержит:\n");

      maxx = sizeof(objs);
      for (x = 0; x < maxx; x++) {
         who->message("  " + objs[x]->query_short() + "\n");
      }
   }
}

static void do_show(object obj1, object obj2, int loud) {
   string name, name2;

   if (!obj1) {
      if (loud) {
         write("Что и кому вы хотите показать?");
      }
      return;
   }

   if (!obj2) {
      if (loud) {
         write("Кому вы хотите показать это?\n");
      }
      return;
   }

   if (obj2 == this_player()) {
      if (loud) {
         write("Вы не можете показывать вещи самому себе.\n");
      }
      return;
   }

   name = obj1->query_short();
   name2 = obj2->query_d_name();

   write("Вы показали " + name + " " + name2 + ".\n");
   this_environment()->tell_room(this_player(), this_player()->query_Name() +
      " показывает " + name + " " + name2 + ".\n");

   display_object(obj2, obj1);
}

static void main(string str) {
   object obj, obj2, *inv;
   int i, max, amount;
   string what, where, coin;

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

   if (sscanf(str, "%s to %s", what, where) == 2) {
   } else if (sscanf(str, "%s %s", what, where) == 2) {
   } else {
      write("Что и кому вы хотите показать?");
      return;
   }

   obj = this_environment()->present(where);
   if (!obj) {
      write("Кому вы хотите это показать?");
      return;
   }

   obj2 = this_player()->present(lowercase(what));
   if (!obj2) {
      obj2 = this_player()->query_environment()->present(lowercase(what));
   }
   do_show(obj2, obj, 1);
}
