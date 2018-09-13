/* read.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: читать [-h] ОБЪЕКТ" });
   lines += ({ "" });
   lines += ({ "Позволяет вам читать то, что можно прочитать." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tчитать знак" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "delete");
   add_also("player", "look");
   add_also("player", "mail");
   add_also("player", "post");
}

static void main(string str) {
   object ob;
   string *lines;

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

   ob = this_environment()->present(str);

   if (ob && ob->is_readable()) {
      if (ob->can_read(this_player())) {
         ob->do_read(this_player());
      } else {
         write("Это нельзя прочесть.");
      }
   } else {
      ob = this_player()->present(str);
      if (ob && ob->is_readable()) {
         if (ob->can_read(this_player())) {
            ob->do_read(this_player());
         } else {
            write("Это нельзя прочесть.");
         }
      } else {
         ob = this_environment()->present("board");
         if (ob) {
            if (!str || (str == "")) {
               write("Читать что?");
               return;
            }

            if (ob->query_msg_exists(str) == 1) {
               lines = explode(ob->query_message(str), "\n");
               write(implode(lines[..3], "\n"));
               this_player()->more(lines[4..]);
            } else {
               write("Нет такого сообщения.\n");
            }
            return;
         } else {
            write("Читать что?");
            return;
         }
      }
   }
}
