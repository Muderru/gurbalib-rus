inherit "/std/weapon";

void setup(void) {
   set_id("кирка");
   add_id("ржавая");
   set_short("Ржавая кирка");
   set_long("Это очень старый инструмент. Его не помешало бы заточить и " +
      "очистить от ржавчины и грязи.");
   set_obj_i_name("ржавая кирка");
   set_obj_r_name("ржавой кирки");
   set_obj_d_name("ржавой кирке");
   set_obj_v_name("ржавую кирку");
   set_obj_t_name("ржавой киркой");
   set_obj_p_name("ржавой кирке");
   set_obj_gender("female");
   set_gettable(1);

   set_min_damage(1);
   set_max_damage(3);
   set_hit_bonus(0);

   set_weapon_skill("combat/sharp/small");

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
   
   set_wield_type("single");
   if (this_player()->query_gender() == "male") {
      set_weapon_action("огрел");
   } else if (this_player()->query_gender() == "female") {
      set_weapon_action("огрела");
   } else {
      set_weapon_action("огрело");
   }   
   
   set_value(8);
   set_size(6);
   set_weight(7);
}
