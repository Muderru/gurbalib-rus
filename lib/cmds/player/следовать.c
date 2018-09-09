/* follow.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: следовать [-h] [WHO]" });
   lines += ({ "" });
   lines += ({ "Позволяет вам следовать или прекратить следовать за другим игроком." });
   lines += ({ "Команда без аргументов, выдаст вам список следующих за вами." 
      });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tследовать туор" });
   lines += ({ "\tследовать" });
   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "attack");
   add_also("player", "cast");
   add_also("player", "eat");
   add_also("player", "enter");
   add_also("player", "go");
   add_also("player", "pray");
   add_also("player", "query");
   add_also("player", "quit");
   add_also("player", "wimpy");
}

/* XXX need to still put backend of this in..... */

static void main(string str) {
   string name;
   object obj;

   if (!alsos) {
      setup_alsos();
   }

   name = this_player()->query_follower();
   if (empty_str(str)) {
      if (name && (name != "")) {
         write("Сейчас вы следуете за: " + name + "\n");
      } else {
         write("Сейчас вы ни за кем не следуете.\n");
      }
      return;
   }

   if (str == this_player()->query_name()) {
      write("Вы не можете следовать за самим собой.\n");
      return;
   }

   if (sscanf(str, "-%s", str)) {
      this_player()->more(usage());
      return;
   }

   /* Stop following whoever we are following */
   if (str == name) {
      this_player()->set_follower("");
      write("Вы прекратили следовать за " + str + ".\n");
      this_environment()->tell_room(this_player(), 
         this_player()->query_Name() + " прекратил следовать за " + 
         capitalize(str) + ".\n");
      obj = USER_D->find_player(name);

      obj->remove_follower(this_player());
      return;
   }

   /* Actually follow someone */
   obj = this_environment()->present(str);
   if (obj) {
      this_player()->set_follower(str);

      write("Вы начали следовать за " + str + ".\n");
      this_environment()->tell_room(this_player(), 
         this_player()->query_Name() + " начал следовать за " + 
         capitalize(str) + ".\n");
       obj->add_follower(this_player());
   } else {
      write("Вы не можете найти: " + str + ".\n");
   }
}
