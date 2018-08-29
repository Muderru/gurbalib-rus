#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("newbie");

   set_short("End of the tunnel");
   set_long("You are at the end of a small tunnel.  The room is brightly " +
      "colored and everything in the room directs your attention " +
      "towards a large red button.");

   set_exits(([
      "north" : DIR + "/rooms/drinkme", 
      "out" : DIR + "/rooms/tree", ]));

   add_item("button", "A giant red BUTTON!\nIt is glowing and says PRESS ME!");
   add_item("red button",
      "A giant red BUTTON!\nIt is glowing and says PRESS ME!");
   add_action("do_push", "push");
   add_action("do_push", "press");
}

int do_push(string arg) {
   if (arg == "button") {
      if (this_player()->is_completed_quest("NewbieVille")) {
         write("The button is already depressed.\n");
      } else {
         this_player()->add_completed_quest("NewbieVille");
         this_player()->increase_expr(200);
         write("Congratulations!!!\n");
         write("You have just completed the NewbieVille " +
            "Quest which earns you 200 exp!\n");
      }
      return 1;
   } else {
      return 0;
   }
}
