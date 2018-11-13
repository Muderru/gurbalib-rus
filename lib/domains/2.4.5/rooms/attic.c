#include "../domain.h"

inherit "/std/room";
inherit "/domains/2.4.5/lib/el";

int lamp_is_lit;
object el;

int query_floor() {
   return 3;
}

void setup(void) {
   add_area("2.4.5");

   set_short("Чердак");

   add_action("press_button", "нажать");
   add_action("press_button", "давить");

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

   str = "Вы находитесь на чердаке церкви. В западной стене вы замечаете дверь, " +
      "а рядом с ней кнопку.";
   if (lamp_is_lit == 1) {
      str += " Рядом с подъемником горит яркая лампа.";
   } else {
      str += " Рядом с подъемником висит потухшая лампа.";
   }

   return str;
}

void lamp_on() {
   lamp_is_lit = 1;
}

void lamp_off() {
   lamp_is_lit = 0;
}

