#include "../domain.h"

inherit "/std/monster";

void setup() {
   object obj;

   set_name("огненный великан");
   set_gender( "male" );
   add_ids("огненный", "великан");
   set_short("Огненный великан");
   set_long("Представьте великана, облитого маслом и подожженного. Он он очень зол.");
   set_r_name("огненного великана");
   set_d_name("огненному великану");
   set_v_name("огненного великана");
   set_t_name("огненным великаном");
   set_p_name("огненном великане");   
   set_race("giant");
   set_level(15);
   set_aggressive(1);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 50);
   set_skill("combat/defense", 100);

   obj = clone_object(DIR + "/obj/fire_sword");
   obj->setup();
   obj->move(this_object());
   do_wield(obj);
}

