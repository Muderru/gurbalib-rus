inherit "/std/armor";

void setup(void) {
   set_id("шляпа", "черная", "потрепанная");
   set_adj("черная");
   set_short("Потрепанная черная шляпа");
   set_long("Эта шляпа видала и лучшие дни, она выглядит так, как будто ее кто-то жевал." +
   "Но, за неимением лучшего, сойдет и она.");
   set_obj_i_name("потрепанная черная шляпа");
   set_obj_r_name("потрепанной черной шляпы");
   set_obj_d_name("потрепанной черной шляпе");
   set_obj_v_name("потрепанную черную шляпу");
   set_obj_t_name("потрепанной черной шляпой");
   set_obj_p_name("потрепанной черной шляпе");
   set_obj_gender("male");
   set_gettable(1);

   set_ac(1);

   set_slot("head");
   set_value(20);
   set_size(5);
   set_weight(7);
}
