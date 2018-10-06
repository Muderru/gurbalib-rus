/* Demonstrates use of m_wander for testing purposes.  Cerihan 3/14/09 */
#include "../domain.h"

inherit "/std/monster";
inherit "/std/modules/m_wander";

void setup(void) {
   set_name("путешественник");
   set_gender("male");
   add_id("странствующий");
   set_short("Странствующий путешественник");
   set_long("Никто не знает, кто он и откуда. И кажется он и сам " +
      "об этом не вспомнит.");
   set_r_name("путешественника");
   set_d_name("путешественнику");
   set_v_name("путешественника");
   set_t_name("путешественником");
   set_p_name("путешественнике");
   set_race("human");
   set_level(random(8) + 5);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 50);
   set_skill("combat/defense", 100);

   set_wander_area("Gurba");
   start_wander(10, 20);
}
