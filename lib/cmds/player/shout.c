inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Usage: shout [-h] MSG" });
   lines += ({ "" });
   lines += ({ "Send MSG to all players on the mud.  This command should " +
      "only be used SPARINGLY." });
   lines += ({ "Don't abuse it or you'll lose it." });
   lines += ({ "" });
   lines += ({ "Options:" });
   lines += ({ "\t-h\tHelp, this usage message." });
   lines += ({ "Examples:" });
   lines += ({ "\tshout I am the fluffy bunny king!" });
   lines += ({ "\tshout no your not!" });

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
      write("A magical muzzle has been placed on you, you can not shout.\n");
      this_player()->query_environment()->tell_room(this_player(),
         this_player()->query_Name() + " tries to shout but " +
         "the words will not come out.\n");
      return;
   }

   usrs = players();

   for (i = 0; i < sizeof(usrs); i++) {
      usrs[i]->message("%^RED%^" + "" +
         this_player()->query_Name() + " shouts: %^RESET%^" + str + "\n");
   }
}
