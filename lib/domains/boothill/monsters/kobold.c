#include "../domain.h"

inherit "/std/monster";

void setup(void) {
   object obj;

   set_name("кобольд");
   set_gender( "male" );
   add_adj("грязный", "маленький");
   set_short("Грязный маленький кобольд");
   set_long("Этот маленький грязный монстр явно не ваш друг. Он смотрит " +
      "на вас злобно и кажется выжидает удобного момента для нападения.");
   set_r_name("грязного маленького кобольда");
   set_d_name("грязному маленькому кобольду");
   set_v_name("грязного маленького кобольда");
   set_t_name("грязным маленьким кобольдом");
   set_p_name("грязном маленьком кобольде");
   set_race("kobold");
   set_level(1);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 50);
   set_skill("combat/defense", 100);
   set_aggressive(1);

   obj = clone_object(DIR + "/obj/minehelm.c");
   obj->setup();
   obj->move(this_object());
   do_wear(obj);
}
