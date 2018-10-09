inherit "/std/weapon";

void set_axe_skill(string s) {
   if (!is_standard_weapon_skill(s)) {
      s = "medium";
   }
   set_weapon_skill("combat/edge/" + s);
}

void setup(void) {
   set_id("топор");
   add_id("боевой");
   set_short("Боевой топор");
   set_long("Самый обычный боевой топор.");
   set_obj_i_name("топор");
   set_obj_r_name("топора");
   set_obj_d_name("топору");
   set_obj_v_name("топор");
   set_obj_t_name("топором");
   set_obj_p_name("топоре");
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
       "рубанул", "резанул", "травмировал", "разрубил"
       }));
   } else if (this_player()->query_gender() == "female") {
    set_weapon_actions(({
       "рубанула", "резанула", "травмировала", "разрубила"
       }));
   } else {
    set_weapon_actions(({
       "рубануло", "резануло", "травмировало", "разрубило"
       }));
   }

   set_axe_skill("medium");

   set_value(30);
   set_size(4);
   set_weight(1);
}

