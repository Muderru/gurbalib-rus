#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("Gurba");
   add_area("MarketStreet");
   add_area("GurbaOutdoor");

   set_short("Рыночная площадь");
   set_long("Вы находитесь в восточной части рыночной площади, " +
      "являющейся торговым центром всех окрестных земель. " +
      "Также это одна из старейших частей города, постройки вокруг " +
      "выглядят очень старомодно, а камни брусчатки по ногами " +
      "отполированы от блеска. Дальше на западе начинается центральная " +
      "площадь города.");

   set_exits(([
      "восток" : DIR + "/rooms/square_west",
      "запад" : DIR + "/rooms/market2",
   ]));
}
