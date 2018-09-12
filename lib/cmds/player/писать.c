/* post.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: писать [-h] ТЕМА" });
   lines += ({ "" });
   lines += ({ "Оставляет сообщение на доске сообщений с указанной темой." });
   lines += ({ "Затем будет вызван простой текстовый редактор для составления " +
      "вашего сообщения." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tписать This is a message" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "delete");
   add_also("player", "look");
   add_also("player", "mail");
   add_also("player", "read");
}

private static mapping msg;
private static mapping subject;
private static mapping ob;

static void main(string str) {

   if (!alsos) {
      setup_alsos();
   }

   if (!msg) {
      msg = ([]);
      subject = ([]);
      ob = ([]);
   }

   if (empty_str(str)) {
      this_player()->more(usage());
      return;
   } else if (sscanf(str, "-%s", str)) {
      this_player()->more(usage());
      return;
   } else if (this_player()->is_dead()) {
      write("Вы не можете сделать этого, пребывая в мире мертвых.\n");
      return;
   } else {
      subject[this_player()->query_name()] = str;
   }

   ob[this_player()->query_name()] = this_environment()->present("board");
   if (!ob[this_player()->query_name()]) {
      write("Вы должны быть около доски сообщений.\n");
      return;
   }

   write(" \nПожалуйста, введите ваш текст ниже.\n" +
      "'.' без ковычек на пустой строке заканчивает сообщение. ~к для отмены.\n" +
      "------------------------------------------------------------" +
      "------------------\n");
   this_player()->input_to_object(this_object(), "enter_line");
   this_player()->set_editing(1);
   msg[this_player()->query_name()] = "";
}

void enter_line(string line) {
   if ((line != ".") && (line != "**") && (line != "~a") && (line != "~к")) {
      if (!msg[this_player()->query_name()]) {
         msg[this_player()->query_name()] = line + "\n";
      } else {
         msg[this_player()->query_name()] = msg[this_player()->query_name()] +
            line + "\n";
      }
      this_player()->input_to_object(this_object(), "enter_line");
   } else {
      if ((line == "~a") || (line == "~к")) {
         write(" \nСообщение отменено.\n");
      } else {
         ob[this_player()->query_name()]->add_message(this_player()->
            query_name(), subject[this_player()->query_name()],
            msg[this_player()->query_name()]);
         write(" \nСообщение оставлено.\n");
      }
      this_player()->set_editing(0);
      this_player()->write_prompt();
      this_environment()->tell_room(this_player(),
      this_player()->query_Name() + " оставляет новое сообщение.\n");
   }
}
