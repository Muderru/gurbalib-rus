#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Берег Острова магов");
   set_long("Вы стоите на берегу Острова магов. Холодные волны  " +
      "накатывают на острые камни. Такая картина наблюдается также " +
      "на западе и востоке, а на юге возвышается холм с остатками " +
      "башни Арканартона - мага жившего здесь.");

   add_exit("юг", DIR + "/rooms/south/sislnd14.c");
   add_exit("восток", DIR + "/rooms/south/sislnd3.c");
   add_exit("запад", DIR + "/rooms/south/sislnd1.c");
}
