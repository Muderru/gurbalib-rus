#include "../domain.h"

inherit "/std/monster";

void setup() {
   object obj;

   set_name("хобгоблин");
   set_gender( "male" );
   set_short("Хобгоблин");
   set_long("Этот хобгоблин выглядит очень мерзко и наверняка у него скверный характер.");
   set_r_name("хобгоблина");
   set_d_name("хобгоблину");
   set_v_name("хобгоблина");
   set_t_name("хобгоблином");
   set_p_name("хобгоблине");   
   set_race("hobgoblin");
   set_level(5);
   set_aggressive(1);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 50);
   set_skill("combat/defense", 100);

   obj = clone_object("/domains/required/objects/coin.c");
   obj->set_amount(random(500) + 1);
   obj->move(obj);
   obj->setup();
}

