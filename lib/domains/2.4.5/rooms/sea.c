#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("В море");
   set_long("Вы плывете в море, рядом с вами перекатываются зеленые " +
   "волны и проплывают разные морские твари. К счастью вроде бы " +
   "хищников среди нет. В нескольких метрах под вами вы можете " +
   "разглядеть дно, к нему можно нырнуть.");

   add_exit("west", DIR + "/rooms/jetty2.c");

   add_action("dive", "нырнуть");
}

int dive(string str) {
   object *inv;
   int i, max;
   string dest;

   inv = this_player()->query_inventory();
   max = sizeof(inv);
   for (i = 0; i < max; i++) {
      if (inv[i]->is_container()) {
         dest = DIR + "/rooms/sea_bottom.c";
         if (this_player()->query_gender() == "male") {
         this_player()->query_environment()->tell_room(this_player(),
            this_player()->query_Name() + " нырнул под воду.\n");
         } else if (this_player()->query_gender() == "female") {
         this_player()->query_environment()->tell_room(this_player(),
            this_player()->query_Name() + " нырнула под воду.\n");
         } else {
         this_player()->query_environment()->tell_room(this_player(),
            this_player()->query_Name() + " нырнуло под воду.\n");
         }
         write("Вы нырнули под воду.\n");
         this_player()->move(dest);
         this_player()->query_environment()->tell_room(this_player(),
            this_player()->query_Name() + " приплыл сверху.\n");
         this_player()->do_look(this_environment());
         return 1;
      }
   }
   write("Вы не можете дышать под водой. Вам нужен " +
      "источник воздуха!");
   this_player()->query_environment()->tell_room(this_player(),
      this_player()->query_Name() + " пытается нырнуть под воду.\n");
   return 1;
}
