/* whisper.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: шепнуть [-h] ИГРОК СООБЩЕНИЕ" });
   lines += ({ "" });
   lines += ({ "Шепнуть сообщение указанному игроку." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tшепнуть туор ты классный." });
   lines += ({ "\tшепнуть туор как у тебя дела?" });

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
   object *usr;
   object usr1;
   int i, flag;
   string what;

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

   sscanf(who, "%s %s", who, what);

   if (what && (what != "")) {
      what = capitalize(what);
   }

   usr = USER_D->query_players();
   usr1 = USER_D->find_player(who);
   flag = 0;
   for (i = 0; i < sizeof(usr); i++) {
      if ((usr[i]->query_environment() == this_environment()) &&
         (usr[i]->query_name() == who)) {
            if (this_player()->query_gender() == "male") {
         usr[i]->message(this_player()->query_Name() +
            " шепнул вам: " + what + "\n");
         this_player()->query_environment()->tell_room(this_player(),
            this_player()->query_Name() +
            " шепнул что-то " + usr1->query_d_name() + ".\n", usr[i]);            
          } else if (this_player()->query_gender() == "female") {
         usr[i]->message(this_player()->query_Name() +
            " шепнула вам: " + what + "\n");
         this_player()->query_environment()->tell_room(this_player(),
            this_player()->query_Name() +
            " шепнула что-то " + usr1->query_d_name() + ".\n", usr[i]);            
          } else {
         usr[i]->message(this_player()->query_Name() +
            " шепнуло вам: " + what + "\n");
         this_player()->query_environment()->tell_room(this_player(),
            this_player()->query_Name() +
            " шепнуло что-то " + usr1->query_d_name() + ".\n", usr[i]);            
          }
         write("Вы шепнули " + usr1->query_d_name() + ": " + what + "\n");
         flag = 1;
      }
   }

   if (!flag) {
      write("Что и кому вы хотите шепнуть?\n");
   }
}

