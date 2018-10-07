inherit "/std/monster";
inherit "/std/modules/m_messages";
inherit "/std/modules/m_triggers";

static mapping stored_items;
static int will_buy, will_sell, restock_delay;

void init_stored_items(void) {
   if (!stored_items) {
      stored_items = ([ ]);
   }
}

string ducats(int val) {
   return val == 1 ? "" : "ов";
}

int is_vendor(void) {
   return 1;
}

void set_restock_delay(int delay) {
   restock_delay = delay;
   call_out("restock", delay);
}

void restock(void) {
   this_object()->setup();
}

void set_will_buy(int will) {
   will_buy = will;
}

int query_will_buy(void) {
   return will_buy;
}

void set_will_sell(int will) {
   will_sell = will;
}

int query_will_sell(void) {
   return will_sell;
}

void after_sale_transfer(object sold_what, object sold_to) {
}

string get_successful_sale_msg() {
   return "$d продали $i.";
}

string emit_successful_sale_msg(object obj, object player) {
   this_object()->other_action(this_object(),
      get_successful_sale_msg(), player, obj);
}

void deduct_coins_from_buyer(int amount, object player) {
   player->add_money("дукат", amount);
}

void sale_transfer(object obj, object player) {
   obj->move(player);
}

void reduce_vendor_inventory(string idx) {
   stored_items[idx] = stored_items[idx] - 1;
}

void handle_sale(string idx, object obj, object player) {
   emit_successful_sale_msg(obj, player);
   deduct_coins_from_buyer(-obj->query_value(), player);
   sale_transfer(obj, player);
   after_sale_transfer(obj, player);
   reduce_vendor_inventory(idx);
}

void do_sell(object player, string what) {
   string *objs;
   object obj;
   int i, maxi;

   init_stored_items();
   objs = map_indices(stored_items);
   maxi = sizeof(objs);
   for (i = 0; i < maxi; i++) {
      obj = clone_object(objs[i]);
      if (obj) {
         obj->move(this_object());
         obj->setup();

         /* Found the object */
         if (obj->query_id() == what) {
            if (stored_items[objs[i]] > 0) {
               if (obj->query_value() <= player->query_total_money() ) {
                  handle_sale(objs[i], obj, player);
                  return;
               }
               write("У вас недостаточно денег для этого.\n");
               obj->query_environment()->remove_object(obj);
               obj->destruct();
               return;
            }
         } else {
            obj->query_environment()->remove_object(obj);
            obj->destruct();
         }
      }
   }

   player->message("У нас нет этой вещи.");
}

void do_buy(object player, object what) {
   string name;
   int value;

   value = what->query_value();

   if ((will_buy < 1) || (value < 1)) {
      write(capitalize(this_object()->query_name()) + " - не купит это.\n");
      return;
   }

   name = what->base_name();

   if (!what->move(this_object())) {
      write("Вы не можете продать это.\n");
      return;
   }

   if (player->query_gender() == "male") {
   player->targeted_action("$N продал $d $i за " + value + " дукат" +
      ducats(value) + ".",
      this_object(), what);
 } else if (player->query_gender() == "female") {
   player->targeted_action("$N продала $d $i за " + value + " дукат" +
      ducats(value) + ".",
      this_object(), what);
 } else {
   player->targeted_action("$N продало $d $i за " + value + " дукат" +
      ducats(value) + ".",
      this_object(), what);
 }
   

   what->query_environment()->remove_object(what);
   what->destruct();

   init_stored_items();
   if (!member_map(name, stored_items)) {
      stored_items[name] = 1;
   } else {
      stored_items[name] = stored_items[name] + 1;
   }

   player->add_money("дукат", value);
}

void add_item(string name, int amount) {

   if (amount == 0) {
      amount = 1;
   }

   init_stored_items();
   stored_items[name] = amount;
}

string build_string(string str, object obj, string num, string *objs) {
   int val;

   val = obj->query_value();
   if (!obj->query_Name()) {
      if (!obj->query_adj() || obj->query_adj() == "") {
         str += " %^CYAN%^[" + num + "]%^RESET%^ " + obj->query_id() +
            ", " + val + " дукат" + ducats(val) + ".\n";
      } else {
         str += " %^CYAN%^[" + num + "]%^RESET%^ " +
            obj->query_adj() + " " + obj->query_id() + ", " +
            val + " дукат" + ducats(val) + ".\n";
      }
   } else {
      val = objs->query_value();
      str += " %^CYAN%^[" + num + "]%^RESET%^ " + obj->query_Name() +
         ", " + val + " дукат" + ducats(val) + ".\n";
   }

   return str;
}

string query_list(void) {
   string str, num, *objs;
   object obj;
   int i, maxi;

   init_stored_items();
   objs = map_indices(stored_items);
   str = "";

   maxi = sizeof(objs);
   for (i = 0; i < maxi; i++) {

      if (stored_items[objs[i]] > 0) {
         obj = clone_object(objs[i]);
         if (obj) {

            obj->move(this_object());
            obj->setup();

            num = "   " + stored_items[objs[i]];
            num = num[strlen(num) - 3..];

            str = build_string(str, obj, num, objs);

            obj->query_environment()->remove_object(obj);
            obj->destruct();
         }
      }
   }
   return str;
}

void do_list(object player) {
   write("%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" +
      "-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^\n\n");
   write(query_list());
   write("%^BLUE%^\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" +
      "-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^\n");
}
