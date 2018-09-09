/* enter.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: войти [-h] OBJECT" });
   lines += ({ "" });
   lines += ({ "Позволяет вам войти в специальный объект.  Чтобы найти" });
   lines += ({ "такой, смотрите по сторонам." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tвойти дыра" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "attack");
   add_also("player", "cast");
   add_also("player", "eat");
   add_also("player", "follow");
   add_also("player", "go");
   add_also("player", "pray");
   add_also("player", "query");
   add_also("player", "quit");
   add_also("player", "wimpy");
}


static void main(string str) {
   string error;

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

   error = this_environment()->body_exit(this_player(), str);

   if (error) {
      write(error);
   }
}
