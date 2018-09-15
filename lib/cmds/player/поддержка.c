/* wizcall.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: поддержка [-h] MSG" });
   lines += ({ "" });
   lines += ({ "Оповестить всех активных админов, что вам нужна помощь." });
   lines += ({ "У вас должна быть серьезная причина для их беспокойства. :)" });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tподдержка Мне нужна помощь, я застрял в комнате, " + 
      "из которой нет выхода." });
   lines += ({ "\tподдержка Я нашел баг в команде закрыть." });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "bug");
   add_also("player", "chan");
   add_also("player", "emote");
   add_also("player", "rsay");
   add_also("player", "say");
   add_also("player", "shout");
   add_also("player", "tell");
   add_also("player", "whisper");
   add_also("wiz", "echo");
   add_also("wiz", "echoto");
   add_also("wiz", "ssay");
   add_also("wiz", "sysmsg");
   add_also("wiz", "translate");
   add_also("wiz", "wizlog");

   add_also("admin", "wall");
}

static void main(string str) {
   int i, flag;
   object *usrs;

   flag = 0;

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

   usrs = USER_D->query_wizards();

   if (str != "") {
      for (i = 0; i < sizeof(usrs); i++) {
         if (query_wizard(usrs[i])) {
            usrs[i]->message("%^RED%^" + "" + this_player()->query_Name() +
               " просит о помощи: %^RESET%^" + str + "\n");
            LOG_D->write_log("wizcall", this_player()->query_Name() + 
               " on " + ctime(time()) + ": " + str + "\n");
         }
      }
   } else {
      write("Добрые админы должны знать причину, по которой вы их отвлекаете " +
         "о чашечки кофе.");
      flag = 1;
   }

   if (flag == 0) {
      write("Вы взываете о помощи.");
   }
}

