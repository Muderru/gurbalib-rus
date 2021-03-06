#include "../domain.h"

inherit "/std/room";

void setup(void) {
   set_short("Кухня");
   set_long("Вы зашли на кухню местной харчевни, хотя больше " +
      "всего это место напоминает хлев. Пищу готовят в каких-то " +
      "корытах, из которых ее накладывают в деревянные миски " +
      "клиентов. В качестве бонусных ингредиентов идут тараканы и крысы.");
   set_exits(([
      "юг" : DIR + "/rooms/restaurant",
   ]));

   add_item("ингредиенты", "Похоже, что еду здесь готовят из пищевых " +
      "отходов, добывая их из мусорных баков. Иногда особо удачливым " +
      "клиентам попадается бонусная порция мяса в виде тараканов и кусков крыс.");
}
