#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Равнина");
   set_long("Вы находитесь на большой равнине, заросшей дикими травами. " +
   "Среди огромных сорняков проглядывают робкие незабудки и васильки. " +
   "Между ними пробегают пугливые мыши-полевки, скрывающиеся от лис и " +
   "соколов.");

   add_exit("север", DIR + "/rooms/plain7.c");
   add_exit("восток", DIR + "/rooms/plain2.c");
}
