/* drop.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: бросить [-h] [все|OBJ]" });
   lines += ({ "" });
   lines += ({ "Позволяет вам избавляться от мусора в инвентаре." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "\tвсе\tВыбросить все, что у вас есть в инвентаре." });
   lines += ({ "Примеры:" });
   lines += ({ "\tбросить меч" });
   lines += ({ "\tбросить все" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "get");
   add_also("player", "put");
   add_also("player", "remove");
   add_also("player", "wear");
   add_also("player", "wield");
}

static int do_drop_coin(int amount, string type) {
   object obj;
   int value;

   value = amount * MONEY_D->query_value(type);

   if (this_player()->query_total_money() >= value) {
      this_player()->add_money(type, -amount);
      write("Вы выбросили " + amount + " " + type + "ов.");
            if (this_player()->query_gender() == "male") {
              this_player()->query_environment()->tell_room(this_player(),
         this_player()->query_Name() + " выбросил " + amount + " " + type +
         "ов.\n");
          } else if (this_player()->query_gender() == "female") {
              this_player()->query_environment()->tell_room(this_player(),
         this_player()->query_Name() + " выбросила " + amount + " " + type +
         "ов.\n");
          } else {
              this_player()->query_environment()->tell_room(this_player(),
         this_player()->query_Name() + " выбросило " + amount + " " + type +
         "ов.\n");
          }
      
      obj = clone_object(DOMAINS_DIR + "/required/objects/coin.c");
      obj->set_amount(amount);
      obj->set_type(type);
      obj->move(this_player()->query_environment());
   } else {
      write("У вас нет столько денег.\n");
   }
   return 1;
}

static int do_drop(object obj, int loud) {
   string slot;
   object worn;

   if (!obj) {
      if (loud) {
         write("Что вы хотите выбросить?");
      }
      return 0;
   }

   if (obj->is_undroppable()) {
      if (loud) {
         write("Вы не можете бросить это.");
      }
      return 0;
   }
   if (obj->query_worn() == 1) {
      if (obj->is_cursed()) {
         if (loud) {
            this_player()->targeted_action("$N пытается избавиться от " + obj->query_obj_r_name() +
               "но неудачно.", nil, obj);
            write("Странно... Эта вещь не хочет покидать вас.\n");
         } 
         return 0;
      } 
      this_player()->do_remove(obj);
      this_player()->targeted_action(obj->query_remove_message(), nil, obj);
      obj->after_unwear(this_player(), "бросить");
   }
   if (obj->query_wielded() == 1) {
      if (obj->is_cursed()) {
         if (loud) {
            this_player()->targeted_action("$N пытается избавиться от " + obj->query_obj_r_name() +
               "но неудачно.", nil, obj);
            write("Странно... Эта вещь не хочет покидать вас.\n");
         } 
         return 0;
      }
      this_player()->do_unwield(obj);
      this_player()->targeted_action(obj->query_unwield_message(), nil, obj);
      obj->after_unwield(obj, "бросить");
   }

   if (obj->move(this_environment())) { 
            if (this_player()->query_gender() == "male") {
              this_player()->targeted_action("$N выбросил " + obj->query_obj_v_name() + ".", nil, obj);
          } else if (this_player()->query_gender() == "female") {
              this_player()->targeted_action("$N выбросила " + obj->query_obj_v_name() + ".", nil, obj);
          } else {
              this_player()->targeted_action("$N выбросило " + obj->query_obj_v_name() + ".", nil, obj);
          }
      obj->post_drop();
      return 1;
   } else {
      this_player()->targeted_action("$N пытается выбросить " + obj->query_obj_v_name() + ", но неудачно.", nil, obj);
      return 0;
   }
}

static void main(string str) {
   object obj;
   object *inv;
   int i, max, amount, done;
   string type;

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
         if (do_drop(inv[i], 0)) {
            done = 1;
         }
      }

      if (!done) {
         write("У вас нет ничего, что можно выбросить.\n");
      }
      return;
   }

   if (sscanf(str, "%d %s", amount, type) == 2) {
      if (do_drop_coin(amount, type)) {
         return;
      }
   }

   obj = this_player()->present(lowercase(str));
   do_drop(obj, 1);
}
