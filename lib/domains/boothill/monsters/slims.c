#include "../domain.h"

inherit "/std/monster";

void setup(void) {
   object obj;

   set_name("слизняк");
   set_gender( "male" );
   add_adj("большой");
   set_short("Большой слизняк");
   set_long("Эта большая куча слизи выглядит очень зловеще. Возможно из-за " +
      "нескольких тянущихся к вам щупалец или дюжины уставившихся на вас глаз.");
   set_r_name("большого слизняка");
   set_d_name("большому слизняку");
   set_v_name("большого слизняка");
   set_t_name("большим слизняком");
   set_p_name("большом слизняке");
   set_race("rodent");
   set_level(1);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 50);
   set_skill("combat/defense", 100);
   set_aggressive(0);

   obj = clone_object(DIR + "/obj/10ghat.c");
   obj->setup();
   obj->move(this_object());
   do_wear(obj);
}
