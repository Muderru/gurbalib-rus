/* shout.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: орать [-h] MSG" });
   lines += ({ "" });
   lines += ({ "Отправляет сообщение MSG всем игрокам в игре.  Не злоупотребляйте " +
      "этой командой." });
   lines += ({ "Не спамьте или ее лишитесь." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tорать Я пушистая крольчиха!" });
   lines += ({ "\tорать Тебе не дам!" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "bug");
   add_also("player", "chan");
   add_also("player", "emote");
   add_also("player", "rsay");
   add_also("player", "say");
   add_also("player", "tell");
   add_also("player", "whisper");
   add_also("player", "wizcall");

   add_also("wiz", "echo");
   add_also("wiz", "echoto");
   add_also("wiz", "ssay");
   add_also("wiz", "sysmsg");
   add_also("wiz", "translate");
   add_also("wiz", "wizlog");

   add_also("admin", "wall");
}

static void main(string str) {
   int i;
   object *usrs;

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

   if (this_player()->query_muzzle()) {
      write("Магический кляп был надет на вас, теперь вы не можете орать.\n");
      this_player()->query_environment()->tell_room(this_player(),
         this_player()->query_Name() + " пытается заорать, но " +
         "лишь хватает ртом воздух.\n");
      return;
   }

   usrs = players();

   for (i = 0; i < sizeof(usrs); i++) {
      usrs[i]->message("%^RED%^" + "" +
         this_player()->query_Name() + " орет: %^RESET%^" + str + "\n");
   }
}
