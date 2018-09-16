#include "../domain.h"

inherit "/std/weapon";

void setup(void) {
   set_id("ветка");
   add_id("ветку");
   set_adj("короткая");
   set_long("Неказистая ветка с дерева.");
   set_short("Ветка");
   set_obj_i_name("ветка");
   set_obj_r_name("ветки");
   set_obj_d_name("ветке");
   set_obj_v_name("ветку");
   set_obj_t_name("веткой");
   set_obj_p_name("ветке");
   set_obj_gender("female");
   set_gettable(1);

   set_min_damage(1);
   set_max_damage(3);
   set_hit_bonus(1);

   set_weapon_skill("combat/blunt/small");

   set_wield_type("single");
   if (this_player()->query_gender() == "male") {
    set_wield_message("$N схватил ветку.");
    set_unwield_message("$N перестал размахивать веткой.");
    set_weapon_action("огрел");
 } else if (this_player()->query_gender() == "female") {
    set_wield_message("$N схватила ветку.");
    set_unwield_message("$N перестала размахивать веткой.");
    set_weapon_action("огрела");
 } else {
    set_wield_message("$N схватило ветку.");
    set_unwield_message("$N перестало размахивать веткой.");
    set_weapon_action("огрело");
 }
   set_value(1);
   set_size(6);
   set_weight(2);
}
