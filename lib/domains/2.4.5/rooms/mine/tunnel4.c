#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Туннель");
   set_long("Вы осторожно пробираетесь по туннелю в глубь старой шахты. " +
   "Сверху на вас валятся комья земли, а с гнилых балок капают капли воды. " +
   "Туннель тянется с севера на юг, из тьмы во тьму. ");

   add_exit("север", DIR + "/rooms/mine/tunnel5.c");
   add_exit("юг", DIR + "/rooms/mine/tunnel3.c");
}
