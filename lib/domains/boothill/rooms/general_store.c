#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("boothill");

   set_short("Магазин всякой всячины");
   set_long("Похоже, что это единственный магазин во всем городе и " +
      "купить здесь можно все самое необходимое для жизни. А, если " +
      "вам понадобится какая-нибудь экзотика, то здесь ее можно заказать в " +
      "столице, правда ждать посылку придется несколько месяцев. Единственный " +
      "выход отсюда ведет на восток на грязную улочку.");

   set_exits(([
      "восток" : DIR + "/rooms/infront_store.c", 
   ]));

   set_objects(
      DIR + "/monsters/will",
      "/domains/required/objects/mer_sign"
   );
}
