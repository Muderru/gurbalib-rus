/* quit.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: конец [-h] [-r]" });
   lines += ({ "" });
   lines += ({ "Один из способов покинуть игру." });
   lines += ({ "Помните, что так вы сохраните ваши деньги, но все ваши " +
      "вещи упадут " });
   lines += ({ "на землю при выходе." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "\t-r\tУдаляет ваш аккаунт.  ВНИМАНИЕ! Этот процесс необратим." });
   lines += ({ "Примеры:" });
   lines += ({ "\tконец" });
   lines += ({ "\tконец -r" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "attack");
   add_also("player", "cast");
   add_also("player", "eat");
   add_also("player", "enter");
   add_also("player", "follow");
   add_also("player", "go");
   add_also("player", "pray");
   add_also("player", "query");
   add_also("player", "wimpy");

   add_also("wiz", "aload");
   add_also("wiz", "forcequit");
}

void verify_remove(string str) {
   if (str == "Y" || str == "y" || str == "д" || str == "да") {
      USER_D->delete_user(this_player()->query_name());
   } else {
      write("Удаление отменено.\n");
   }
}

static void main(string str) {

   if (!alsos) {
      setup_alsos();
   }

   if (!empty_str(str)) {
      if (str == "-r") {
         write("ВНИМАНИЕ! Этот процесс необратим.\n");
         write("Вы уверены, что хотите удалить вашего персонажа? (д|н)\n");
         this_player()->input_to_object(this_object(), "verify_remove");
         return;
      }
      this_player()->more(usage());
      return;
   }

   this_player()->do_quit();
}
