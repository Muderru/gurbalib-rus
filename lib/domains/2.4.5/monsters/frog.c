#include "../domain.h"

inherit "/std/monster";

void setup() {
   object obj;

   set_name("маленькая лягушка");
   add_ids("лягушка", "маленькая");
   set_short("Маленькая лягушка");
   set_long("Мерзкая слизистая тварь, уставилась на вас не моргая.");
   set_r_name("маленькой лягушки");
   set_d_name("маленькой лягушке");
   set_v_name("маленькую лягушку");
   set_t_name("маленькой лягушкой");
   set_p_name("маленькой лягушке");
   set_gender( "female" );
   set_race("frog");
   set_level(2);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 50);
   set_skill("combat/defense", 100);

   obj = clone_object(DIR + "/obj/crown");
   obj->setup();
   obj->move(this_object());
   do_wear(obj);
}

