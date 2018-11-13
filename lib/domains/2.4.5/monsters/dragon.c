#include "../domain.h"

inherit "/std/monster";

int count;

void setup() {
   object obj;

   set_name("дракон");
   add_id("пещерный");   
   set_short("Пещерный дракон");
   set_long("Огромный монстр с острыми когтями и клыками.");
   set_r_name("дракона");
   set_d_name("дракону");
   set_v_name("дракона");
   set_t_name("драконом");
   set_p_name("драконе");   
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
}

