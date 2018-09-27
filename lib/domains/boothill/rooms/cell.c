#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("boothill");

   set_short("Тюремная камера");
   set_long("Вы зачем-то зашли в небольшую камеру, пустующую сейчас. "+
   "Стены и пол камеры покрыты пятнами крови в мочи, от перевернутого " +
   "помойного ведра несет дерьмом.");

   set_exits(([
      "запад" : DIR + "/rooms/jail.c", 
   ]));

}
