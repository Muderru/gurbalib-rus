inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Usage: inventory [-h]" });
   lines += ({ "" });
   lines += ({ "Print a list of the items you currently have acquired." });
   lines += ({ "" });
   lines += ({ "Options:" });
   lines += ({ "\t-h\tHelp, this usage message." });
   lines += ({ "Examples:" });
   lines += ({ "\tinventory" });

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
      write("You are carrying nothing.\n");
   } else {
      lines = ({ "You are carrying:" });
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
