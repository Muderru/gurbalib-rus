#include "../domain.h"

inherit "/std/monster";
inherit "/std/modules/m_triggers";

void setup() {
   object obj, obj2;

   set_name("осьминог");
   add_id("большой");
   set_short("Осьминог");
   set_long("Вы видите огромного осьминога с длинными и цепкими щупальцами.");
   set_r_name("осьминога");
   set_d_name("осьминогу");
   set_v_name("осьминога");
   set_t_name("осьминогом");
   set_p_name("осьминоге");
   set_gender("male");

   set_level(10);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 50);
   set_skill("combat/defense", 100);

   obj = clone_object(DIR + "/obj/chest.c");
   obj->move(this_object());
   obj->setup();

   obj2 = clone_object("/domains/required/objects/coin.c");
   obj2->set_amount(random(500) + 1);
   obj2->move(obj);
   obj2->setup();
}

string query_miss_message() {
   if (random(1)) {
      return "Осьминог издает шипящий звук.";
   } else {
      return "Осьминог тянет к вам свои щупальца!";
   }
}
