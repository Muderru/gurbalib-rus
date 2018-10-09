inherit "/std/weapon";

void set_sword_skill(string s) {
   if (!is_standard_weapon_skill(s)) {
      s = "medium";
   }
   set_weapon_skill("combat/edge/" + s);
}

void setup(void) {
   set_id("меч");
   add_id("длинный");
   set_short("Длинный меч");
   set_long("Самый обычный длинный меч.");
   set_obj_i_name("длинный меч");
   set_obj_r_name("длинного меча");
   set_obj_d_name("длинному мечу");
   set_obj_v_name("длинный меч");
   set_obj_t_name("длинным мечом");
   set_obj_p_name("длинном мече");
   set_obj_gender("male");
   set_gettable(1);

   set_combat_stats(1, 5, 10);

   set_wield_type("single");
   if (this_player()->query_gender() == "male") {
    set_wield_message("$N вооружился " + this_object()->query_obj_t_name() + ".");
    set_unwield_message("$N перестал использовать " + this_object()->query_obj_v_name() + ".");
   } else if (this_player()->query_gender() == "female") {
    set_wield_message("$N вооружилась " + this_object()->query_obj_t_name() + ".");
    set_unwield_message("$N перестала использовать " + this_object()->query_obj_v_name() + ".");
   } else {
    set_wield_message("$N вооружилось " + this_object()->query_obj_t_name() + ".");
    set_unwield_message("$N перестало использовать " + this_object()->query_obj_v_name() + ".");
   }   

   if (this_player()->query_gender() == "male") {
    set_weapon_actions(({
       "рубанул", "резанул", "полоснул", "пырнул", "задел", "ранил"
       }));
   } else if (this_player()->query_gender() == "female") {
    set_weapon_actions(({
       "рубанула", "резанула", "полоснула", "пырнула", "задела", "ранила"
       }));
   } else {
    set_weapon_actions(({
       "рубануло", "резануло", "полоснуло", "пырнуло", "задело", "ранило"
       }));
   }   

   set_sword_skill("medium");

   set_value(30);
   set_size(2);
   set_weight(2);
}
