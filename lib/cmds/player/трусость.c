/* wimpy.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: трусость [-h] [CMD ARG]" });
   lines += ({ "" });
   lines += ({ "Команда трусость поможет вам установить когда и куда " +
      "вам бежать из боя." });
   lines += ({ "" });
   lines += ({ "Если не указывать параметров, то команда даст информацию " +
      "по текущим настройкам." });
   lines += ({ "CMDS могут быть следующими: вкл, выкл, напр, хп" });
   lines += ({ "ARG указывается только для напр и хп." });
   lines += ({ "Аргумент напр указывает на направление, в котором вы будете " +
      "пытаться сбежать. " });
   lines += ({ "Если для напр не указать направления, то будет очищено установленное." });
   lines += ({ "Аргумент для хп это число, если количество ваших очков жизни " +
      "упадет ниже него, то вы попытаетесь сбежать." });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tтрусость" });
   lines += ({ "\tтрусость выкл" });
   lines += ({ "\tтрусость напр север" });
   lines += ({ "\tтрусость напр" });
   lines += ({ "\tтрусость хп 10" });

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
   add_also("player", "pray");
   add_also("player", "query");
   add_also("player", "quit");
}

static void main(string str) {
   mixed tmp;
   string dir;
   int hp;

   if (!alsos) {
      setup_alsos();
   }

   if (empty_str(str)) {
      if (this_player()->query_wimpy() == 1) {
         write("Режим трусости: вкл\n");
      } else {
         write("Режим трусости: выкл\n");
      }

      tmp = this_player()->query_wimpy_dir();
      if (stringp(tmp)) {
         dir = tmp;
      } else {
         dir = "\"\"";
      }
      write("Трусость, направление побега: " + dir + "\n");

      tmp = this_player()->query_wimpy_hp();
      if (intp(tmp)) {
         hp = tmp;
      } else {
         hp = 0;
      }
      write("Трусость хп: " + hp + "\n");
   } else if (sscanf(str, "-%s", str)) {
      this_player()->more(usage());
   } else if (str == "dir" || str == "direction" || str == "напр" || str == "направление") {
      this_player()->set_wimpy_dir("");
      write("Трусость, направление побега: сброшено.\n");
   } else if (sscanf(str, "напр %s", dir) == 1) {
      this_player()->set_wimpy_dir(dir);
      write("Трусость, направление побега = " + dir + "\n");
   } else if (sscanf(str, "хп %d", hp) == 1) {
      this_player()->set_wimpy_hp(hp);
      write("Трусость хп = " + hp + "\n");
   } else if (str == "вкл") {
      this_player()->set_wimpy(1);
      write("Режим трусости включен.\n");
   } else if (str == "выкл") {
      this_player()->set_wimpy(0);
      write("Режим трусости выключен.\n");
   } else {
      this_player()->more(usage());
   }
}
