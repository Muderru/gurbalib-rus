#include "../domain.h"

inherit "/std/room";

void setup(void) {
   set_short("Банк Гурбы");
   set_long("Вы зашли в просторное помещение с двумя рядами кабинок " +
      "клерков с обеих сторон.  Все внутри обделано изысканным белым " +
      "мрамором, потолок также поддерживают ряды стройных мраморных колонн.");

   set_exits(([
      "юг" : DIR + "/rooms/border_south9",
   ]));

   add_item("кабинка", "кабинки",
      "Каждая кабинка сделана из толстых дубовых досок.");
   add_item("клерк", "клерки",
      "Местные клерки совсем не разговорчивы. " +
      "Вам кажется, что они не слишком подходят для этой работы.");
   add_item("пол", "колонны", "колонна", "Все вокруг кажется изящным " +
      "и утонченным. Камень, из которого они изготовлены, напоминает " +
      "мрамор, но есть в нем что-то странное.");

   set_objects("/domains/required/objects/bank_sign.c");
}
