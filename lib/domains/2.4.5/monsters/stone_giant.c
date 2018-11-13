#include "../domain.h"

inherit "/std/monster";

void setup() {
   object obj;

   set_name("гигант");
   set_gender( "male" );
   add_ids("каменный", "каменный гигант", "каменного гиганта");
   set_short("Каменный гигант");
   set_long("Вы видите огромную человекоподобную фигуру из отполированного камня.");
   set_r_name("каменного гиганта");
   set_d_name("каменному гиганту");
   set_v_name("каменного гиганта");
   set_t_name("каменным гигантом");
   set_p_name("каменном гиганте");
   set_race("giant");
   set_level(15);
   set_aggressive(1);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 50);
   set_skill("combat/defense", 100);

   obj = clone_object(DIR + "/obj/stone_sword");
   obj->setup();
   obj->move(this_object());
   do_wield(obj);
}

