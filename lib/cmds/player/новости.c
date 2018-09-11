/* motd.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: новости [-h]" });
   lines += ({ "" });
   lines += ({ "Позволяет вам увидеть сообщение дня." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tновости" });

   lines += get_alsos();

   return lines;
}

setup_alsos() {
   add_also("player", "fortune");
}

static void main(string str) {
   if (!alsos) {
      setup_alsos();
   }

   if (empty_str(str)) {
      string *lines;

      lines = explode(TELNET_D->query_motd(), "\n");
      this_player()->more(lines);
   } else {
      this_player()->more(usage());
   }
}
