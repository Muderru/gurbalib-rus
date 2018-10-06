#include "../domain.h"

inherit "/std/monster";

void setup(void) {
   set_name("тварь");
   add_id("огромная");
   set_gender("female");
   set_short("Огромная тварь");
   set_long("Эта тварь настолько огромна, что с легкостью растопчет любого человека.");
   set_r_name("твари");
   set_d_name("твари");
   set_v_name("тварь");
   set_t_name("тварью");
   set_p_name("твари");
   set_level(15);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 250);
   set_skill("combat/defense", 200);
}
