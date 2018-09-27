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

   set_wield_type("single");
   set_weapon_action("slash");
   set_value(8);
   set_size(6);
   set_weight(7);
}
