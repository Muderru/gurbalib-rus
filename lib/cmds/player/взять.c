/* get.c */
inherit M_COMMAND;
inherit "/std/modules/m_messages";

string *usage(void) {
   string *lines;

   lines = ({ "Использование: взять [-h] [все|OBJ] [from OBJ2]" });
   lines += ({ "" });
   lines += ({ "Позволяет вам подобрать указанный предмет OBJ или взять " +
      "один предмет из другого." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "\tвсе\tВзять все, что только можно." });
   lines += ({ "Примеры:" });
   lines += ({ "\tвзять меч" });
   lines += ({ "\tвзять меч из сундук" });
   lines += ({ "\tвзять все" });
   lines += ({ "\tвзять все из сундука" });
   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "drop");
   add_also("player", "open");
   add_also("player", "put");
   add_also("player", "remove");
   add_also("player", "wear");
   add_also("player", "wield");
}

static int get_coins(object here, int amount, string type) {
   object obj;
   string str;
   int value;

   obj = here->present("монета");
   value = obj->query_value();
   if (amount > value) {
      write("Тут нет столько монет.\n");
   } else {
      type = obj->query_currency();
            if (this_player()->query_gender() == "male") {
              str = "$N взял " + amount + " " + type + "ов.";
          } else if (this_player()->query_gender() == "female") {
               str = "$N взяла " + amount + " " + type + "ов.";
          } else {
               str = "$N взяло " + amount + " " + type + "ов.";
          }
      this_player()->targeted_action(str, this_player());

      if (amount == value) {
         destruct_object(obj);
      } else {
         obj->set_value(value - amount);
      }
      this_player()->add_money(type, amount);
   }

   return 1;
}

static int do_get(object obj1, object obj2, int loud) {
   string slot;
   object worn;

   if (!obj1) {
      if (loud) {
         write("Что вы хотите взять?");
      }
      return 0;
   }

   if (obj1->is_gettable() != 1) {
      if (loud) {
         write("Вы не можете взять " + obj1->query_obj_i_name() + ".");
      }
      return 0;
   }

   if (!obj2) {
      if (loud) {
         write("Откуда вы хотите это взять?\n");
      }
      return 0;
   }

   if (!obj2->is_container()) {
      if (loud) {
         write("Вы не можете взять это отсюда.\n");
      }
      return 0;
   }
   if (obj2->is_living()) {
      if (loud) {
         write("Почему бы вам не попросить об этом?\n");
      }
      return 0;
   }

   if (obj2->is_closed()) {
      if (loud) {
         write("Закрыто.\n");
      }
      return 0;
   }

   if (obj1->is_money()) {
      int x;

      x = obj1->query_value();
      get_coins(obj1->query_environment(), x, obj1->query_currency());
      return 1;
   }

   if (!this_player()->can_carry(obj1)) {
      this_player()->message("Ваш инвентарь полон и вы " +
         "не можете нести еще и " + obj1->query_obj_i_name() + ".");
      return 1;
   }

   if (obj1->move(this_player())) {
      if (obj2 == this_environment()) {
            if (this_player()->query_gender() == "male") {
              this_player()->targeted_action("$N взял " + obj1->query_obj_v_name() + ".", nil, obj1);
          } else if (this_player()->query_gender() == "female") {
               this_player()->targeted_action("$N взяла " + obj1->query_obj_v_name() + ".", nil, obj1);
          } else {
               this_player()->targeted_action("$N взяло " + obj1->query_obj_v_name() + ".", nil, obj1);
          }
      } else {
            if (this_player()->query_gender() == "male") {
              this_player()->targeted_action("$N взял " + obj1->query_obj_v_name() + " из " + obj2->query_obj_r_name() + ".", obj2, 
            obj1);
          } else if (this_player()->query_gender() == "female") {
               this_player()->targeted_action("$N взяла " + obj1->query_obj_v_name() + " из " + obj2->query_obj_r_name() + ".", obj2, 
            obj1);
          } else {
               this_player()->targeted_action("$N взяло " + obj1->query_obj_v_name() + " из " + obj2->query_obj_r_name() + ".", obj2, 
            obj1);
          }
         
      }
      return 1;
   } else {
      if (obj2 == this_environment()) {
            if (this_player()->query_gender() == "male") {
              this_player()->targeted_action("$N попытался взять " + obj1->query_obj_i_name() + ", но неудачно.", nil, obj1);
          } else if (this_player()->query_gender() == "female") {
               this_player()->targeted_action("$N попыталась взять " + obj1->query_obj_i_name() + ", но неудачно.", nil, obj1);
          } else {
               this_player()->targeted_action("$N попыталось взять " + obj1->query_obj_i_name() + ", но неудачно.", nil, obj1);
          }
      } else {
            if (this_player()->query_gender() == "male") {
              this_player()->targeted_action("$N попытался взять " + obj1->query_obj_i_name() + " из " + obj2->query_obj_r_name() + ", но неудачно.", obj2, 
            obj1);
          } else if (this_player()->query_gender() == "female") {
               this_player()->targeted_action("$N попыталась взять " + obj1->query_obj_i_name() + " из " + obj2->query_obj_r_name() + ", но неудачно.", obj2, 
            obj1);
          } else {
               this_player()->targeted_action("$N попыталось взять " + obj1->query_obj_i_name() + " из " + obj2->query_obj_r_name() + ", но неудачно.", obj2, 
            obj1);
          }
      }
   }
   return 0;
}

static void main(string str) {
   object obj, obj2, *inv;
   int i, max, done, amount;
   string what, where, type;

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
   } else if (sscanf(str, "%s из %s", what, where) == 2) {
   } else if (sscanf(str, "%s %d", what, amount) == 2) {
      what = str;
   } else if (sscanf(str, "%s %s", what, where) == 2) {
   } else if (sscanf(str, "%d %s", amount, type) == 2) {
      if (get_coins(this_environment(), amount, type)) {
         return;
      } else {
         what = str;
      }
   } else {
      what = str;
   }

   if (!where || (where == "")) {
      obj = this_environment();
   } else {
      obj = this_environment()->present(lowercase(where));
   }

   if (!obj) {
      write("Что и откуда вы хотите взять?");
      return;
   }

   if (what == "все") {
      if (obj->is_closed()) {
         write("Закрыто.\n");
         return;
      }  

      inv = obj->query_inventory();
      max = sizeof(inv);
      done = 0;

      for (i = 0; i < max; i++) {
         if (do_get(inv[i], obj, 0)) {
            done = 1;
         }
      }
      if (!done) {
         write("Здесь нечего взять.\n");
      }
      return;
   }

   obj2 = obj->present(lowercase(what));
   do_get(obj2, obj, 1);
}
