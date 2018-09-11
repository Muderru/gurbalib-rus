/* killedby.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: смерти [-h]" });
   lines += ({ "" });
   lines += ({ "Выводит информацию по вашим смертям..." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tсмерти" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "score");
}

static void main(string str) {
   string *lines;

   if (!alsos) {
      setup_alsos();
   }

   if (!empty_str(str)) {
      this_player()->more(usage());
      return;
   }

   lines = this_player()->summarise_killers();
   this_player()->more(lines);
}

