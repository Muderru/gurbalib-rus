#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Сумеречный лес");
   set_long("Вы стоите в окружении мрачных искривленных деревьев. " +
   "На их черных ветвях нет ни единого зеленого листочка. Вокруг " +
   "вас раздаются непонятные шорохи и звуки. Лес кажется мертвым, " +
   "но и живым одновременно.");

   add_exit("север", DIR + "/rooms/south/sshore7.c");
   add_exit("юг", DIR + "/rooms/south/sforst18.c");
   add_exit("восток", DIR + "/rooms/south/sforst16.c");
   add_exit("запад", DIR + "/rooms/south/sshore8.c");
}
