#include "../domain.h"

inherit "/std/monster";
inherit "/std/modules/m_triggers";

int count;

void setup() {
   object obj;

   set_name("костяной дракон");
   add_ids("дракон", "костяной", "дракона");
   set_short("Костяной дракон Арканартона");
   set_long("Это огромный дракон-нежить, созданный магом Арканартоном " +
       "в своих безумных экспериментах.");
   set_r_name("костяного дракона");
   set_d_name("костяному дракону");
   set_v_name("костяного дракона");
   set_t_name("костяным драконом");
   set_p_name("костяном драконе");
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 100);
   set_skill("combat/defense", 100);
   set_level(17);
   set_aggressive(1);

   obj = clone_object(DIR + "/obj/gem");
   obj->setup();
   obj->move(this_object());

   obj = clone_object("/domains/required/objects/coin.c");
   obj->set_amount(random(500) + 1);
   obj->move(this_object());
   obj->setup();

   set_spell_chance(50);
   set_spell_damage(100);
   set_spell_message("Костяной дракон выдохнул струю " +
      "ядовитого дыма в $w.\n");
}
