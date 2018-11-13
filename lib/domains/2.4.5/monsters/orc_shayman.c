#include "../domain.h"

inherit "/std/monster";
inherit "/std/modules/m_triggers";

void setup() {
   object obj;

   set_name("шаман");
   set_gender( "male" );
   add_ids("орк", "шаман", "шаман орков");
   set_short("Шаман орков");
   set_long("Вы видите уродливого шамана орков. Он намного шире " +
      "обычных орков.");
   set_r_name("шамана орков");
   set_d_name("шаману орков");
   set_v_name("шамана орков");
   set_t_name("шаманом орков");
   set_p_name("шамане орков");
   set_race("orc");
   set_level(10);
   set_aggressive(1);

   set_spell_chance(20);
   set_spell_damage(20);
   set_spell_message("Шаман орков запускает магический снаряд в $w.");

   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 50);
   set_skill("combat/defense", 100);

   obj = clone_object(DIR + "/obj/gold_staff.c");
   obj->setup();
   obj->move(this_object());
   obj = clone_object(DIR + "/obj/orc_slayer.c");
   obj->setup();
   obj->move(this_object());
   do_wield(obj);
}
