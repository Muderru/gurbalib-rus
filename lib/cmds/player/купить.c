/* buy.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: купить [-h] OBJ" });
   lines += ({ "" });
   lines += ({ "Позволяет вам купить предмет OBJ, " +
      "когда вы находитесь рядом с продавцом." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tкупить меч" });
   lines += ({ "\tкупить шлем" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "extinguish");
   add_also("player", "identify");
   add_also("player", "light");
   add_also("player", "list");
   add_also("player", "listen");
   add_also("player", "look");
   add_also("player", "search");
   add_also("player", "sell");
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
   object *objs;
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

   objs = this_environment()->query_inventory();
   for (i = 0; i < sizeof(objs); i++) {
      if (objs[i]->is_vendor() == 1) {
         /* Found the shopkeeper */

         objs[i]->do_sell(this_player(), str);
         return;
      }
   }

   write("У кого вы хотите купить?");
}
