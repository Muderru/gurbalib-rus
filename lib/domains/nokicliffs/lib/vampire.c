#include "../domain.h"

inherit DIR + "/lib/undead";

int is_vampire(void) {
   return 1;
}

void create(void) {
   ::create();
   set_race("vampire");
   add_bane("garlic");
   add_vulnerability("silver");
}

