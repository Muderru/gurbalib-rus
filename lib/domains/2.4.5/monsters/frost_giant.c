#include "../domain.h"

inherit "/std/monster";

void setup() {
   object obj;

   set_name("ледяной великан");
   set_gender( "male" );
   add_ids("ледяной", "великан");
   set_short("Ледяной великан");
   set_long("Огромная гора льда движется к вам, испуская " +
      "волны холода и ненависти.");
   set_r_name("ледяного великана");
   set_d_name("ледяному великану");
   set_v_name("ледяного великана");
   set_t_name("ледяным великаном");
   set_p_name("ледяном великане");
   set_race("giant");
   set_level(15);
   set_aggressive(1);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 50);
   set_skill("combat/defense", 100);

   obj = clone_object(DIR + "/obj/frost_sword");
   obj->setup();
   obj->move(this_object());
   do_wield(obj);
}

