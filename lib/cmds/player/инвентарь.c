/* inventory.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: инвентарь [-h]" });
   lines += ({ "" });
   lines += ({ "Выводит список того, что есть у вас с собой." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tинвентарь" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "hp");
   add_also("player", "junk");
   add_also("player", "levels");
   add_also("player", "score");
   add_also("player", "skills");
   add_also("player", "top");

   add_also("wiz", "status");
}

static void main(string str) {
   object *inv;
   int i;
   string loc, *lines;

   if (!alsos) {
      setup_alsos();
   }

   if (!empty_str(str)) {
      this_player()->more(usage());
      return;
   }

   inv = this_player()->query_inventory();

   if (sizeof(inv) == 0) {
      write("У вас нет ничего.\n");
   } else {
      lines = ({ "Вы несете:" });
      for (i = 0; i < sizeof(inv); i++) {
         loc = "  " + inv[i]->query_short();
         if (inv[i]->is_wielded() || inv[i]->is_worn()) {
            loc += " %^CYAN%^[";
               if (inv[i]->is_wielded() ) {
                  loc += inv[i]->query_wield_position();
               }
               if (inv[i]->is_worn()) {
                 loc +=  inv[i]->query_wear_position();
               }
               loc += "]%^RESET%^";
         }
         lines += ({ loc });
      }
      this_player()->more(lines, 1);
   }
}
