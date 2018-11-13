#include "../domain.h"

inherit "/std/vendor";

void setup(void) {
   set_name("бармен");
   add_ids("косоглазый", "хозяин бара", "торговец");
   set_gender("male");
   set_short("Косоглазый бармен");
   set_long("Он не слишком то любит, когда люди на него пялятся. Но пойло у него отменное.");
   set_r_name("бармена");
   set_d_name("бармену");
   set_v_name("бармена");
   set_t_name("барменом");
   set_p_name("бармене");   
   set_race("human");
   set_level(15);

   set_restock_delay(7200);
   set_will_buy(1);

   add_item(DIR + "/obj/classbeer", 20);
   add_item(DIR + "/obj/special", 10);
   add_item(DIR + "/obj/firebreath", 10);
}
