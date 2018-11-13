#include "../domain.h"

inherit "/std/room";
inherit "/domains/2.4.5/lib/el";

object el;
int lamp_is_lit;

int query_floor() {
   return 1;
}

void setup(void) {
   add_area("2.4.5");

   set_short("Зал билдеров");

   add_action("press_button", "нажать");
   add_action("press_button", "давить");

   set_objects (DIR + "/monsters/leo.c");

   el = get_el();
   if (el) {
      if (el->query_location() == query_floor()) {
         tell_room(this_object(), "Лампа гаснет.\n");
         el_arrives();
      } else {
         el_leaves();
      }
   }
}

string query_long() {
   string str;

   str = "Вы в впечатляющем зале билдеров. На западе вы видите " +
      "металлическую дверь, рядом с которой находится большая кнопка. " +
      "На западе ваш путь преграждает силовое поле.\n";

   if (lamp_is_lit) {
     str += " Рядом с подъемником горит яркая лампа.\n";
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

