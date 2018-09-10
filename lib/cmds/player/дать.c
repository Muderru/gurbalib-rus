/* give.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: дать [-h] [все|OBJ] PLAYER" });
   lines += ({ "" });
   lines += ({ "Позволяет дать вам предмет OBJ другому игроку PLAYER" });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "\tвсе\tДать все, что вы несете, другому игроку PLAYER." });
   lines += ({ "Примеры:" });
   lines += ({ "\tдать меч туор" });
   lines += ({ "\tдать все туор" });
   lines += ({ "\tдать 5 монет туор" });
   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "get");
   add_also("player", "drop");
}

static void do_give(object obj1, object obj2, int loud) {
   string slot;
   object worn;

   if (!obj1) {
      if (loud) {
         write("Что вы пытаетесь дать?");
      }
      return;
   }

   if (!obj2) {
      if (loud) {
         write("Кому вы пытаетесь дать?\n");
      }
      return;
   }

   if (!obj2->is_living()) {
      if (loud) {
         write("Вы можете давать предметы только живым существам.\n");
      }
      return;
   }

   if (obj2 == this_player()) {
      if (loud) {
         write("Вы не можете дать предмет самому себе.\n");
      }
      return;
   }

   if (obj1->is_worn()) {
      if (obj1->is_cursed()) {
         this_player()->targeted_action("$N без успеха пытается снять " + obj1->query_obj_i_name() + ".",
            nil, obj1);
         write("Странно... Это не снимается.\n");
         return;
      } else {
         this_player()->do_remove(obj1);
         this_player()->targeted_action(obj1->query_remove_message(), 
            nil, obj1);
         obj1->after_unwear(this_player(), "дать");
      }
   }

   if (obj1->is_wielded()) {
      if (obj1->is_cursed()) {
         this_player()->targeted_action("$N без успеха пытается снять " + obj1->query_obj_i_name() + ".", nil, obj1);
         write("Странно... Это не снимается.\n");
         return;
      } else {
         this_player()->do_unwield(obj1);
         this_player()->targeted_action(obj1->query_unwield_message(), 
            nil, obj1);
         obj1->after_unwield(this_player(), "дать");
      }
   }

   if (obj1->move(obj2)) {
            if (this_player()->query_gender() == "male") {
               this_player()->targeted_action("$N дал " + obj1->query_obj_i_name() + " " + obj2->query_d_name() +".", obj2, obj1);
          } else if (this_player()->query_gender() == "female") {
               this_player()->targeted_action("$N дала " + obj1->query_obj_i_name() + " " + obj2->query_d_name() +".", obj2, obj1);
          } else {
               this_player()->targeted_action("$N дало " + obj1->query_obj_i_name() + " " + obj2->query_d_name() +".", obj2, obj1);
          }
   } else {
      this_player()->targeted_action("$N безуспешно пытается дать " + obj1->query_obj_i_name() + " " + obj2->query_d_name() +".",
         obj2, obj1);
   }
}

static int transfer_money(int amount, string cointype, string where) {
   object obj;
   int worth;

   obj = this_environment()->present(where);

   if (!obj) {
      write("Кому вы пытаетесь это дать?");
      return 0;
   }
   if (!obj->is_living()) {
      write("Вы не можете дать деньги этому.\n");
      return 0;
   }
   if (obj == this_player()) {
      write("Вы не можете дать самому себе деньги.\n");
      return 0;
   }

   worth = MONEY_D->query_value(cointype);
   if (worth > 0) {
      worth = amount * worth;
      if (this_player()->query_total_money() > worth) {
         this_player()->add_money(cointype, -amount);
         obj->add_money(cointype, amount);
            if (this_player()->query_gender() == "male") {
                       this_player()->targeted_action("$N дал " + amount +
            " " + cointype + "ов " + obj->query_obj_d_name() + ".", obj);
          } else if (this_player()->query_gender() == "female") {
                        this_player()->targeted_action("$N дала " + amount +
            " " + cointype + "ов " + obj->query_obj_d_name() + ".", obj);
          } else {
                        this_player()->targeted_action("$N дало " + amount +
            " " + cointype + "ов " + obj->query_obj_d_name() + ".", obj);
          }         
         return 1;
      } else {
         write("У вас недостаточно денег.\n");
         return 0;
      }
   } else {
      write("Ну ничего себе, какая щедрость.\n");
      return 0;
   }
   return 0;
}

static void main(string str) {
   object obj, obj2;
   object *inv;
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
      if (sscanf(what, "%d %s", amount, coin) == 2) {
         if (MONEY_D->is_currency(coin)) {
            transfer_money(amount, coin, where);
            return;
         }
      }
   } else if (sscanf(str, "%s %s", what, where) == 2) {
   } else {
      write("Что и кому вы хотите дать?");
      return;
   }

   obj = this_environment()->present(where);
   if (!obj) {
      write("Что и кому вы хотите дать?");
      return;
   }

   if (what == "все") {
      inv = this_player()->query_inventory();
      max = sizeof(inv);
      for (i = 0; i < max; i++) {
         do_give(inv[i], obj, 0);
      }
      return;
   }

   obj2 = this_player()->present(lowercase(what));
   if (!obj2) {
      obj2 = this_player()->query_environment()->present(lowercase(what));
   }
   do_give(obj2, obj, 1);
}
