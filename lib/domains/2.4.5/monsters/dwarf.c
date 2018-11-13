#include "../domain.h"

inherit "/std/monster";
inherit "/std/modules/m_block_exits";

void setup() {
   set_name("дварф");
   set_gender( "male" );
   add_id("коренастый");
   set_short("Коренастый дварф");
   set_long("Хотя дварф невелик, но очень плотно сложен. В силе он не уступит человеку.");
   set_r_name("дварфа");
   set_d_name("дварфу");
   set_v_name("дварфа");
   set_t_name("дварфом");
   set_p_name("дварфе");   
   set_race("dwarf");
   set_aggressive(1);
   set_level(10);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 50);
   set_skill("combat/defense", 100);
   add_block("север");
}

int do_block(object who) {
   return 1;
}
