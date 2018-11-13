#include "../domain.h"

inherit "/std/monster";

int count;

void setup() {
   object obj;

   set_name("черная крыса");
   add_ids("черная", "крыса");
   set_short("Уродливая черная крыса");
   set_long("Этот грызун настоящий великан.");
   set_r_name("черной крысы");
   set_d_name("черной крысе");
   set_v_name("черную крысу");
   set_t_name("черной крысой");
   set_p_name("черной крысе");
   set_gender( "female" );
   set_race("rat");
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 50);
   set_skill("combat/defense", 100);
   set_level(3);
   set_aggressive(1);

   obj = clone_object(DIR + "/obj/stone.c");
   obj->setup();
   obj->move(this_object());
}

