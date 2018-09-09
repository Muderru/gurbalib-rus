/* extinguish.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: погасить [-h] [OBJECT]" });
   lines += ({ "" });
   lines += ({ "Погашает или выключает выбранный источник света." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tпогачить факел" });
   lines += ({ "\tпогасить лампу" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "buy");
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

static void main(string str) {
   if (!alsos) {
      setup_alsos();
   }

   this_player()->more(usage());
}

