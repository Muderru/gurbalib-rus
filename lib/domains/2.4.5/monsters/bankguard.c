#include "../domain.h"

inherit "/std/monster";
inherit "/std/modules/m_triggers";
inherit "/std/modules/m_block_exits";

void setup() {
   object obj;

   set_name("охранник");
   set_gender( "male" );
   set_short("Охранник банка");
   set_long("Большой и грузный мужик, готовый навалять любому.");
   set_r_name("охранника");
   set_d_name("охраннику");
   set_v_name("охранника");
   set_t_name("охранником");
   set_p_name("охраннике");
   set_race("human");
   set_level(11);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 50);
   set_skill("combat/defense", 100);

   obj = clone_object(DIR + "/obj/bankkey.c");
   obj->setup();
   obj->move(this_object());
   obj = clone_object("/domains/required/objects/short_sword.c");
   obj->setup();
   obj->move(this_object());
   do_wield(obj);
}
