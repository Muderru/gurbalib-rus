#include "../domain.h"

inherit "/std/room";

void setup(void) {
   set_short("Цветовод Фрида");
   set_long("Это небольшое помещение - цветочный магазин. Все внутри " +
      "украшено разноцветными букетами разных размеров. В цветных горшках " +
      "выставлены на продажу разные экзотические растения. ");
   set_exits(([
      "северо-восток" : DIR + "/rooms/square_southwest",
   ]));

   add_item("цветы", "Здесь можно найти цветы любого цвета, формы и " +
      "размера. Стоит только приблизиться к ним, как вас окутывает " +
      "облако их тонких ароматов.");
   add_item("горшки", "горшок", "цветочный горшок", "Каждый горшок " +
      "здесь чем-нибудь да отличается. Но в основном они из дерева или глины.");

   set_objects(
      DIR + "/monsters/frida",
      "/domains/required/objects/mer_sign"
   );
}
