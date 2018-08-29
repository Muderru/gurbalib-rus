inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Usage: attack [-h] [OBJECT]" });
   lines += ({ "" });
   lines += ({ "OBJ offends you, you are going to destroy it." });
   lines += ({ "" });
   lines += ({ "Options:" });
   lines += ({ "\t-h\tHelp, this usage message." });
   lines += ({ "Examples:" });
   lines += ({ "\tattack rat" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "cast");
   add_also("player", "eat");
   add_also("player", "enter");
   add_also("player", "follow");
   add_also("player", "go");
   add_also("player", "pray");
   add_also("player", "query");
   add_also("player", "quit");
   add_also("player", "wimpy");
}

static void main(string str) {
   object obj;

   if (!alsos) {
      setup_alsos();
   }

   if (!str && (str != "")) {
      this_player()->more(usage());
      return;
   }

   if (sscanf(str, "-%s", str)) {
      this_player()->more(usage());
      return;
   }

   if (this_player()->is_dead()) {
      write("You can not do that when your are not among the living.\n");
      return;
   }

   obj = this_player()->query_environment()->present(lowercase(str));
   if (!obj) {
      write("Attack what?\n");
      return;
   }

   if (!obj->is_living() || obj->is_dead()) {
      write("You can not attack that.\n");
      return;
   }

   if (obj == this_player()) {
      write("You can not attack yourself.\n");
      return;
   }

   if (this_player()->is_fighting() ) {
      write("You are already in combat.\n");
      return;
   }

   this_player()->targeted_action("$N $vattack $t.", obj);
   this_player()->attack(obj);
}
