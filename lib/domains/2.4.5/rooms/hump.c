#include "../domain.h"

inherit "/std/room";

void setup(void) {
   object ob;
   string name;
   add_area("2.4.5");

   set_short("Покатый мост");
   set_long("Вы находитесь на старом каменном мосту, перекинутым " +
   "изящной аркой над небольшой речкой. Хотя камни моста покрыты " +
   "густым мхом, он кажется достаточно крепким и безопасным.");

   add_exit("восток", DIR + "/rooms/vill_green.c");
   add_exit("запад", DIR + "/rooms/wild1.c");

   set_objects (DIR + "/obj/torch.c");

   name = "/domains/required/objects/coin.c";
   if (!present(name)) {
      ob = clone_object(name);
      ob->set_amount(10);
      ob->move(object_name(this_object()));
      ob->setup();
   }
}
