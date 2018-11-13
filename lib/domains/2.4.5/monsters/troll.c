#include "../domain.h"

inherit "/std/monster";
inherit "/std/modules/m_triggers";

#define INTERVAL 5
int count;

void setup() {
   set_name("тролль");
   add_ids("огромный", "страшный", "тролля");
   set_short("Огромный страшный тролль");
   set_long("Этот тролль выглядит как гнилое дерево.");
   set_r_name("тролля");
   set_d_name("троллю");
   set_v_name("тролля");
   set_t_name("троллем");
   set_p_name("тролле");
   set_race("troll");
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 50);
   set_skill("combat/defense", 100);
   set_level(8);
   set_aggressive(1);
}

void do_extra_actions() {
   count = count + 1;
   if (count >= INTERVAL) {
      switch(random(2)) {
         case 0:
            respond("говорить Мясо...");
            break;
         case 1:
            respond("говорить А потом я зайду к твоей матушке!");
            break;
         default:
            respond("говорить Крушить!");
            break;
      }
      count = 0;
   }
}
