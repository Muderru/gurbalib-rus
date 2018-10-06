#include "../domain.h"

inherit "/std/room";

void setup(void) {
   set_short("Магазин доспехов Тимоса");
   set_long("Этот небольшой, но очень опрятный магазин ориентирован " +
      "строго на торговлю доспехами. Это очевидно по стенам, завешанными " +
      "разными образцами металлических и кожаных доспехов. Являясь " +
      "основным поставщиком доспехов для Гильдии бойцов Гурбы, " +
      "кентавр Тимос стал респектабельным торговцем и обладателем стабильного дохода. " +
      "Не проходит и минуты, как какой-нибудь искатель приключений приходит " +
      "сюда с просьбой подобрать ему подходящие доспехи.");

   set_exits(([
      "север" : DIR + "/rooms/square_southeast",
   ]));

   add_item("доспех", "доспехи", "щиты", "щит",
      "Самые разные щиты и доспехи развешены по стенам.");
   add_item("плакат", "На плакате написано: \"Лучше быть бедным, но защищенным, " +
      "чем богатым, но мертвым!\"");
}
