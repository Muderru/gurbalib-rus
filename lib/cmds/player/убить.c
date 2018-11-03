/* attack.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: убить [-h] [OBJECT]" });
   lines += ({ "" });
   lines += ({ "OBJ это то, что мешает вашему комфортному существованию." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tубить крыса" });

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
      write("Вы не можете сделать этого, пребывая в мире мертвых.\n");
      return;
   }

   obj = this_player()->query_environment()->present(lowercase(str));
   if (!obj) {
      write("Убить кого?\n");
      return;
   }

   if (!obj->is_living() || obj->is_dead()) {
      write("Вы не можете убить это.\n");
      return;
   }

   if (obj == this_player()) {
      write("Вы не можете убить себя таким образом.\n");
      return;
   }

   if (this_player()->is_fighting() ) {
      write("Вы уже сражаетесь.\n");
      return;
   }

   this_player()->message("Вы пытаетесь убить " + obj->query_v_name() + ".", 1);
   this_environment()->tell_room(this_player(),
   this_player()->query_name() + " пытается убить " + obj->query_v_name() + ".");
   this_player()->attack(obj);
}
