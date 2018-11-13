#include "../domain.h"

inherit "/std/monster";

void setup() {
   set_name("великан");
   set_short("Великан");
   set_long("Огромный человекоподобный монстр, который способен " +
   "растоптать вас в одно мгновение.");
   set_gender( "male" );
   set_r_name("великана");
   set_d_name("великану");
   set_v_name("великана");
   set_t_name("великаном");
   set_p_name("великане");   
   set_aggressive(1);
   set_race("giant");
   set_level(15);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 50);
   set_skill("combat/defense", 100);
}

