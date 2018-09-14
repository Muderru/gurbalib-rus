/* tell.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: сказать [-h] КОМУ ЧТО" });
   lines += ({ "" });
   lines += ({ "Отправить сообщение указанному игроку.  Если вы хотите сказать что-то "
      });
   lines += ({ "игроку из другого мада, используйте user@MUD.  Если в названии мада "
      });
   lines += ({ "есть пробелы, вам нужно заключить его в \"'."
      });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Examples:" });
   lines += ({ "\tсказать туор я твой фанат." });
   lines += ({ "\tсказать \"sirdude@Dead Souls Dev\" Hi how are you?" });

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

static void main(string who) {
   object usr;
   string what, where;

   if (!alsos) {
      setup_alsos();
   }

   if (empty_str(who)) {
      this_player()->more(usage());
      return;
   }

   if (sscanf(who, "-%s", who)) {
      this_player()->more(usage());
      return;
   }

   if (sscanf(who, "\"%s\" %s", who, what) != 2) {
      sscanf(who, "%s %s", who, what);
   }

   if (!what || (what == "")) {
      write("Что вы хотите сказать?\n");
      return;
   }

   if (sscanf(who, "%s@%s", who, where) == 2) {
      /* intermud tell */
      IMUD_D->do_tell(who, where, what);
      this_player()->message("Вы сказали %^PLAYER%^" + capitalize(who) + "@" +
         where + "%^RESET%^: %^TELL_TO%^" + what + "%^RESET%^\n", 1);
   } else {
      who = lowercase(who);
      usr = USER_D->find_player(who);
      if (usr && (!usr->query_ignored(this_player()->query_name())
            || query_wizard(this_player()))) {
     if (this_player()->query_gender() == "male") {
         usr->message("%^PLAYER%^" + this_player()->query_Name() +
            "%^RESET%^%^TELL_FROM%^ сказал вам: " + what + "%^RESET%^\n", 1);
   } else if (this_player()->query_gender() == "female") {
         usr->message("%^PLAYER%^" + this_player()->query_Name() +
            "%^RESET%^%^TELL_FROM%^ сказала вам: " + what + "%^RESET%^\n", 1);
   } else {
         usr->message("%^PLAYER%^" + this_player()->query_Name() +
            "%^RESET%^%^TELL_FROM%^ сказало вам: " + what + "%^RESET%^\n", 1);
   }  
         usr->set_last_tell(lowercase(this_player()->query_name()));
         this_player()->message("Вы сказали " + "%^PLAYER%^" + usr->query_d_name() +
            "%^RESET%^: %^TELL_TO%^" + what + "%^RESET%^\n", 1);
      } else {
         write(who + " не услышит.\n");
      }
   }
}
