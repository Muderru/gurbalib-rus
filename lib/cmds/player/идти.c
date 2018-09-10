/* go.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: идти [-h] НАПРАВЛЕНИЕ" });
   lines += ({ "" });
   lines += ({ "Позволяет передвигаться вам в выбранном направлении.  Чтобы " +
      "определить " });
   lines += ({ "куда можно идти, осмотритесь вокруг." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tидти север" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "attack");
   add_also("player", "cast");
   add_also("player", "eat");
   add_also("player", "enter");
   add_also("player", "follow");
   add_also("player", "pray");
   add_also("player", "query");
   add_also("player", "quit");
   add_also("player", "wimpy");
}

static void main(string str) {
   string error, str2;
   int len;

   if (!alsos) {
      setup_alsos();
   }

   if (empty_str(str)) {
      this_player()->more(usage());
      return;
   }
   if (sscanf(str, "-%s", str) || sscanf(str, "%s -%s", str, str2)) {
      this_player()->more(usage());
      return;
   }

   len = strlen(str);
   if (str[len - 1] == ' ') {
      str = str[..len - 2];
   }

   error = this_environment()->body_exit(this_player(), str);

   if (error) {
      write(error);
   }
}
