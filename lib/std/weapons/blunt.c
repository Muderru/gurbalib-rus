inherit "/std/weapon";

void set_blunt_skill(string s) {
   if (!is_standard_weapon_skill(s)) {
      s = "medium";
   }
   set_weapon_skill("combat/blunt/" + s);
}

void setup(void) {
   set_id("дубинка");
   set_short("Дубинка");
   set_long("Самая обычная дубинка из крепкого дерева.");
   set_obj_i_name("дубинка");
   set_obj_r_name("дубинки");
   set_obj_d_name("дубинке");
   set_obj_v_name("дубинку");
   set_obj_t_name("дубинкой");
   set_obj_p_name("дубинке");
   set_obj_gender("female");
   set_gettable(1);

   set_combat_stats(1, 5, 10);

   set_wield_type("single");

   if (this_player()->query_gender() == "male") {
    set_wield_message("$N взял в руку " + this_object()->query_obj_v_name() + ".");
    set_unwield_message("$N перестал использовать " + this_object()->query_obj_v_name() + ".");
   } else if (this_player()->query_gender() == "female") {
    set_wield_message("$N взяла в руку " + this_object()->query_obj_v_name() + ".");
    set_unwield_message("$N перестала использовать " + this_object()->query_obj_v_name() + ".");
   } else {
    set_wield_message("$N взяло в руку " + this_object()->query_obj_v_name() + ".");
    set_unwield_message("$N перестало использовать " + this_object()->query_obj_v_name() + ".");
   }
   
   if (this_player()->query_gender() == "male") {
    set_weapon_actions(({
       "огрел", "сокрушил", "стукнул", "саданул", "треснул"
       }));
   } else if (this_player()->query_gender() == "female") {
    set_weapon_actions(({
       "огрела", "сокрушила", "стукнула", "саданула", "треснула"
       }));
   } else {
    set_weapon_actions(({
       "огрело", "сокрушило", "стукнуло", "садануло", "треснуло"
       }));
   }   

   set_blunt_skill("medium");

   set_value(30);
   set_size(2);
   set_weight(1);
}
