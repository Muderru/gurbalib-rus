inherit "/std/weapon";

void set_polearm_skill(string s) {
   if (!is_standard_weapon_skill(s)) {
      s = "medium";
   }
   set_weapon_skill("combat/sharp/" + s);
}

void setup(void) {
   set_id("копье");
   set_short("Копье");
   set_long("Простое, но эффективное копье.");
   set_obj_i_name("копье");
   set_obj_r_name("копья");
   set_obj_d_name("копью");
   set_obj_v_name("копье");
   set_obj_t_name("копьем");
   set_obj_p_name("копье");
   set_obj_gender("neuter");
   set_gettable(1);

   set_combat_stats(1, 5, 10);

   set_wield_type("both");
   if (this_player()->query_gender() == "male") {
    set_wield_message("$N схватил " + this_object()->query_obj_t_name() + ".");
    set_unwield_message("$N перестал использовать " + this_object()->query_obj_v_name() + ".");
   } else if (this_player()->query_gender() == "female") {
    set_wield_message("$N схватила " + this_object()->query_obj_t_name() + ".");
    set_unwield_message("$N перестала использовать " + this_object()->query_obj_v_name() + ".");
   } else {
    set_wield_message("$N схватило " + this_object()->query_obj_t_name() + ".");
    set_unwield_message("$N перестало использовать " + this_object()->query_obj_v_name() + ".");
   }

   if (this_player()->query_gender() == "male") {
    set_weapon_actions(({
       "уколол", "ткнул", "кольнул"
       }));
   } else if (this_player()->query_gender() == "female") {
    set_weapon_actions(({
       "уколола", "ткнула", "кольнула"
       }));
   } else {
    set_weapon_actions(({
       "укололо", "ткнуло", "кольнуло"
       }));
   }   

   set_polearm_skill("medium");

   set_value(30);
   set_size(4);
   set_weight(1);
}
