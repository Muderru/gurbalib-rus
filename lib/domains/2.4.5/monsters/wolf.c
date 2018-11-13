#include "../domain.h"

inherit "/std/monster";

void setup() {
   set_name("волк");
   set_race("wolf");
   /* Leave out the gender specification, get a random one */
   set_gender( "male" );
   add_ids("серый", "серый волк", "волка");
   set_short("Серый волк");
   set_long("Вы видите серого волка, бегущего недалеко от вас. У него " +
   "затравленный взгляд, но огромные клыки.");
   set_r_name("серого волка");
   set_d_name("серому волку");
   set_v_name("серого волка");
   set_t_name("серым волком");
   set_p_name("сером волке");
   set_level(6);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 50);
   set_skill("combat/defense", 100);
}

