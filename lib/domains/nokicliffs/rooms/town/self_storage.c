#include "../../domain.h"

inherit DIR + "/lib/room";

void setup(void) {
   set_short("Noki Town self storage service");
   set_long("You are at the self storage service " +
      "of Noki Town. You can store your gear here " +
      "and unwind, perhaps in the bath house to " +
      "the west. Otherwise, east takes you back " +
      "to the town square.");
   set_exits(([
      "east" : DIR + "/rooms/town/square_south.c",
      "west" : DIR + "/rooms/town/public_bath.c"
   ]));
}

