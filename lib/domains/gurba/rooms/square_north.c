#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("Gurba");
   add_area("GurbaSquare");
   add_area("GurbaOutdoor");

   set_short("Центральная площадь - Север");
   set_long("Северная часть центральной площади города переполнена " +
      "скоморохами и музыкантами, соревнующихся за внимание и деньги " +
      "прохожих. Правда обычной наградой за опасные трюки и грязные " +
      "частушки служат крики одобрения, а не звонкие монеты. " +
      "Местные жители довольно скупы и не особо ценят искусство.");

   set_exits(([
      "восток" : DIR + "/rooms/square_northeast",
      "запад" : DIR + "/rooms/square_northwest",
      "юг" : DIR + "/rooms/square_center",
      "север" : DIR + "/rooms/borland1",
   ]));

   add_item("скоморохи", "Женщины и мужчины, разодетые в яркие " +
      "одежды, пляшут и исполняют опасные трюки. Тут есть мимы, " +
      "акробаты и канатоходцы, любой найдет зрелище по душе.");
   add_item("музыканты", "Музыканты издают тут что-то напоминающее " +
      "музыку из своих самодельных инструментов. От их музыки с округи " +
      "разбежались все кошки и собаки, также считается, что их музыку " +
      "не выносит и нечистая сила.");
}
