/* hp.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: хп [-h]" });
   lines += ({ "" });
   lines += ({ "Короткий путь, чтобы узнать ваши: очки жизни, маны, " +
      "усталости, ac" });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tхп" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "inventory");
   add_also("player", "junk");
   add_also("player", "levels");
   add_also("player", "score");
   add_also("player", "skills");
   add_also("player", "top");

   add_also("wiz", "status");
}

static void main(string str) {
   string line;

   if (!alsos) {
      setup_alsos();
   }

   if (!empty_str(str)) {
      this_player()->more(usage());
      return;
   }

   line = this_player()->get_status(this_player());
   write(line);
}
