#include "../domain.h"

inherit "/std/monster";

void setup(void) {
   object obj;

   set_name("худой пьяница");
   set_gender( "male" );
   add_ids("худой", "пьяница");
   set_short("Худой пьяница");
   set_long("Это несчастное существо почти не похоже на человека. А, может " +
      "он и не человек вовсе. У него налитые кровью глаза и трясущиеся руки.");
   set_r_name("худого пьяницы");
   set_d_name("худому пьянице");
   set_v_name("худого пьяницу");
   set_t_name("худым пьяницей");
   set_p_name("худом пьянице");
   set_race("rodent");
   set_level(1);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 50);
   set_skill("combat/defense", 100);
   set_aggressive(0);

   obj = clone_object(DIR + "/obj/10ghat.c");
   obj->setup();
   obj->move(this_object());
   do_wear(obj);
}
