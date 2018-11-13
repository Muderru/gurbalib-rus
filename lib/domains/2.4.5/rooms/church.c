#include "../domain.h"

inherit "/std/room";
inherit "/domains/2.4.5/lib/el";

object el;
int lamp_is_lit;

int query_floor() {
   return 2;
}

void setup(void) {
   add_area("2.4.5");

   set_short("Деревенская церковь");

   add_exit("юг", DIR + "/rooms/vill_green.c");

   add_action("press_button", "нажать");
   add_action("press_button", "давить");

   add_item("часы", "Кажется, что часы сломаны. Они остановились на 1:26.");
   add_item("яма", "В центре церкви вы видите глубокую яму. В древние " +
      "времена ее использовали для жертвоприношений, но сейчас местные " +
      "жители вроде бы отказались от этой традиции.");

   el = get_el();
   if (el) {
      if (el->query_location() == query_floor()) {
         el_arrives();
      } else {
         el_leaves();
      }
   }
}

string query_long() {
   string str;

   str = "Вы зашли в местную церковь. В ее центре вырыта " +
      "огромная яма, а в западной стене вы видите дверь. " +
      "Рядом с дверью есть кнопка. Священнослужители раньше " +
      "тут общались с духами, сейчас же в основном отпевают  " +
      "мертвецов. Также тут есть часы. Через дверь на юге можно " +
      "выйти на улицу. ";

   if (lamp_is_lit) {
      str += "Рядом с подъемником горит яркая лампа.\n";
   } else {
      str += "Рядом с подъемником висит потухшая лампа.\n";
   }

   return str;
}

void lamp_on() {
   lamp_is_lit = 1;
}

void lamp_off() {
   lamp_is_lit = 0;
}

