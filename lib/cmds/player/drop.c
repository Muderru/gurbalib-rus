inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Usage: drop [-h] [all|OBJ]" });
   lines += ({ "" });
   lines += ({ "Allows you to drop a given object OBJ." });
   lines += ({ "" });
   lines += ({ "Options:" });
   lines += ({ "\t-h\tHelp, this usage message." });
   lines += ({ "\tall\tDrop everything you are carrying." });
   lines += ({ "Examples:" });
   lines += ({ "\tdrop sword" });
   lines += ({ "\tdrop all" });

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
      write("you drop " + amount + " " + type + "s.");
      this_player()->query_environment()->tell_room(this_player(),
         this_player()->query_Name() + " drops " + amount + " " + type +
         "s.\n");
      obj = clone_object(DOMAINS_DIR + "/required/objects/coin.c");
      obj->set_amount(amount);
      obj->set_type(type);
      obj->move(this_player()->query_environment());
   } else {
      write("You do not have that much money.\n");
   }
   return 1;
}

static int do_drop(object obj, int loud) {
   string slot;
   object worn;

   if (!obj) {
      if (loud) {
         write("what are you trying to drop?");
      }
      return 0;
   }

   if (obj->is_undroppable()) {
      if (loud) {
         write("You cannot drop that.");
      }
      return 0;
   }
   if (obj->query_worn() == 1) {
      if (obj->is_cursed()) {
         if (loud) {
            this_player()->targeted_action("$N $vtry to remove $o, " +
               "but $vfumble.", nil, obj);
            write("Strange... It won't come off.\n");
         } 
         return 0;
      } 
      this_player()->do_remove(obj);
      this_player()->targeted_action(obj->query_remove_message(), nil, obj);
      obj->after_unwear(this_player(), "drop");
   }
   if (obj->query_wielded() == 1) {
      if (obj->is_cursed()) {
         if (loud) {
            this_player()->targeted_action("$N $vtry to remove $o, " +
               "but $vfumble.", nil, obj);
            write("Strange... It won't come off.\n");
         } 
         return 0;
      }
      this_player()->do_unwield(obj);
      this_player()->targeted_action(obj->query_unwield_message(), nil, obj);
      obj->after_unwield(obj, "drop");
   }

   if (obj->move(this_environment())) { 
      this_player()->targeted_action("$N $vdrop $o.", nil, obj);
      obj->post_drop();
      return 1;
   } else {
      this_player()->targeted_action("$N $vtry to drop $o, but $vfail.", 
         nil, obj);
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
      write("You can not do that when your are not among the living.\n");
      return;
   }

   if (str == "all") {
      inv = this_player()->query_inventory();
      max = sizeof(inv);
      for (i = 0; i < max; i++) {
         if (do_drop(inv[i], 0)) {
            done = 1;
         }
      }

      if (!done) {
         write("You have nothing to drop.\n");
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
