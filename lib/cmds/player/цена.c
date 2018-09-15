/* value.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: цена [-h] OBJ" });
   lines += ({ "" });
   lines += ({ "Вычисляет и выводит примерную стоимость выбранного предмета" +
         "." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tцена меч" });
   lines += ({ "\tцена шлем" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "buy");
   add_also("player", "extinguish");
   add_also("player", "identify");
   add_also("player", "light");
   add_also("player", "list");
   add_also("player", "listen");
   add_also("player", "look");
   add_also("player", "search");
   add_also("player", "sell");

   add_also("wiz", "last");
   add_also("wiz", "locate");
   add_also("wiz", "mudlist");
   add_also("wiz", "possess");
   add_also("wiz", "rwho");
   add_also("wiz", "snoop");
   add_also("wiz", "where");
   add_also("wiz", "who");
}

static void main(string str) {
   int chance, roll, value;
   int diff;                    /*Difference between roll and chance */
   int dev;                     /*Deviation from the actual value */
   object obj;

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

   str = lowercase(str);

   obj = this_player()->present(str);
   if (!obj) {
      obj = this_environment()->present(str);
   }

   if (!obj) {
      write("Вы не видите " + str + " здесь.");
      return;
   }

   if (!obj->is_living() && obj->query_value()) {

      chance = this_player()->query_skill("value");
      roll = random(5000);
      if (roll > chance) {
         diff = roll - chance;
         dev = random(diff);
         if (random(2) == 1) {
            value = obj->query_value() * (1 + (diff / 100));
         } else {
            value = obj->query_value() + (1 - (diff / 100));
         }
      } else {
         value = obj->query_value();
      }
      write("Вам кажется, что цена этого предмета составляет " + value +
         " золотых монет.\n");
   } else {
      write("вы не можете оценить это.");
   }
}
