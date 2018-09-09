/* describe.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: описание [-h] [ОПИСАНИЕ]" });
   lines += ({ "" });
   lines += ({ "Позволяет вам изменить ваше ОПИСАНИЕ, которое будет видно " +
      "когда кто-нибудь посмотрит на вас." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tописание Ушастый маленький эльф." });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "alias");
   add_also("player", "ansi");
   add_also("player", "clear");
   add_also("player", "ignore");
   add_also("player", "passwd");

   add_also("admin", "coloradm");
}

static void main(string str) {

   if (!alsos) {
      setup_alsos();
   }

   if (empty_str(str)) {
      write("Ваше текущее описание:\n   " + this_player()->query_long() +
         "\n");
      return;
   }
   if (sscanf(str, "-%s", str)) {
      this_player()->more(usage());
      return;
   }

   if (str) {
      str = replace_string(str, "$N", this_player()->query_Name());
   }

   this_player()->set_long(str);
            if (this_player()->query_gender() == "male") {
              this_player()->simple_action("$N сменил внешний вид.");
          } else if (this_player()->query_gender() == "female") {
              this_player()->simple_action("$N сменила внешний вид.");
          } else {
              this_player()->simple_action("$N сменило внешний вид.");
          }
}
