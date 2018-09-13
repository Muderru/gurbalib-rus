/* sell.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: продать [-h] OBJ" });
   lines += ({ "" });
   lines += ({ "Позволяет вам продать предмет OBJ, " +
      "когда вы находитесь около торговца." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tпродать меч" });
   lines += ({ "\tпродать шлем" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "buy");
   add_also("player", "extinguish");
   add_also("player", "identify");
   add_also("player", "light");
   add_also("player", "list");
   add_also("player", "listen");
   add_also("player", "look");
   add_also("player", "search");
   add_also("player", "value");

   add_also("wiz", "last");
   add_also("wiz", "locate");
   add_also("wiz", "mudlist");
   add_also("wiz", "possess");
   add_also("wiz", "rwho");
   add_also("wiz", "snoop");
   add_also("wiz", "where");
   add_also("wiz", "who");
}

/* Created by Fudge */

static void main(string str) {
   object obj, *objs;
   int i;

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

   obj = this_player()->present(str);
   if (obj) {
      /* Found the item */

      objs = this_environment()->query_inventory();
      for (i = 0; i < sizeof(objs); i++) {
         if (objs[i]->is_vendor() == 1) {
            /* Found the shopkeeper */

            if (obj->is_worn()) {
               this_player()->do_remove(obj);
               this_player()->targeted_action(obj->query_remove_message(), nil,
                  obj);
               obj->after_unwear(this_player(), "продать");
            }

            if (obj->is_wielded()) {
               this_player()->do_unwield(obj);
               this_player()->targeted_action(obj->query_unwield_message(),
                  nil, obj);
               obj->after_unwield(this_player(), "продать");
            }

            if (obj->is_undroppable()) {
                write("Вы не можете расстаться с " + obj->query_obj_t_name() + ".\n");
                this_player()->query_environment()->tell_room(this_player(),
                this_player()->query_Name() + " не может расстаться с " + obj->query_obj_t_name() + ".\n");                
                return;
            }

            objs[i]->do_buy(this_player(), obj);
            return;

         }
      }
      write("Продать кому?");
   }
   write("У вас этого нет.");
}

