#include "../domain.h"

inherit "/std/monster";

void setup(void) {
   set_name("кролик");
   add_adj("саблезубый");
   set_short("Огромный саблезубый кролик");
   set_long("Он выглядит нелепо, но опасно.");
   set_r_name("огромного саблезубого кролика");
   set_d_name("огромному саблезубому кролику");
   set_v_name("огромного саблезубого кролика");
   set_t_name("огромным саблезубым кроликом");
   set_p_name("огромном саблезубом кролике");
   set_gender("male");
   set_race("rodent");
   set_level(1);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 20);
   set_skill("combat/defense", 20);
}
