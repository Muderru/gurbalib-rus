#include "../domain.h"

inherit "/std/weapon";

void setup(void) {
   set_id("меч");
   add_id("короткий");
   set_short("Короткий меч");
   set_long("Самый обычный короткий меч, да еще и ржавый.");
   set_obj_i_name("короткий меч");
   set_obj_r_name("короткого меча");
   set_obj_d_name("короткому мечу");
   set_obj_v_name("короткий меч");
   set_obj_t_name("коротким мечом");
   set_obj_p_name("коротком мече");
   set_obj_gender("male");
   set_gettable(1);

   set_min_damage(1);
   set_max_damage(5);
   set_hit_bonus(10);

   set_wield_type("single");
/*   
   set_wield_message("$N $vgrab $p $o. Ready!");
   set_unwield_message("$N $vloosen $p $vgrip on $o, and $vput it away.");
*/  
   if (this_player()->query_gender() == "male") {
   set_weapon_action("рубанул");
 } else if (this_player()->query_gender() == "female") {
   set_weapon_action("рубанула");
 } else {
   set_weapon_action("рубануло");
 }
   set_weapon_skill("combat/sharp/small");

   set_value(30);
   set_size(1);
   set_weight(8);
}
