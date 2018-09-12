/* pray.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: молиться [-h] [молитва]" });
   lines += ({ "" });
   lines += ({ "Позволяет вам восстановить ваше тело...." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tмолиться одобрите мне имя" });

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
   add_also("player", "query");
   add_also("player", "quit");
   add_also("player", "wimpy");
}

static void main(string str) {
   object obj;

   if (!alsos) {
      setup_alsos();
   }

   if (empty_str(str)) {
      write("Вы помолились.\n");
      this_player()->query_environment()->tell_room(this_player(), 
         this_player()->query_Name() + " молится.\n");
   } else if (sscanf(str, "-%s", str)) {
      this_player()->more(usage());
      return;
   } else {
      switch (str[strlen(str) - 1]) {
         case '.':
         case '?':
         case '!':
         case ',':
            break;
         default:
            str += ".";
            break;
      }

      write("Вы молитесь: " + str + ".\n");
      this_player()->query_environment()->tell_room(this_player(), 
         this_player()->query_Name() + " молится: " + str + ".\n");
   }

   if (this_player()->is_dead()) {
      write("Вы чувствуете божественную силу исцеляющую ваше тело.");
      this_player()->query_environment()->tell_room(this_player(), 
         "Божественная сила воскресила " + this_player()->query_v_name() + ".");
      this_player()->set_hp(1);
      this_player()->set_dead(0);
   }
}
