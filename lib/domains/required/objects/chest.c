inherit "/std/container";
inherit "/std/modules/m_openable";
#define DIR "/domains/required"

void setup(void) {
   set_id("сундук", "большой", "деревянный");
   set_short("Большой деревянный сундук");
   set_long("Этот сундук выглядит так, будто весит тонну.  И его не сдвинуть с места.");
   set_obj_i_name("большой деревянный сундук");
   set_obj_r_name("большого деревянного сундука");
   set_obj_d_name("большому деревянному сундуку");
   set_obj_v_name("большой деревянный сундук");
   set_obj_t_name("большим деревянным сундуком");
   set_obj_p_name("большом деревянном сундуке");
   set_obj_gender("male");
   set_open_state(0);
   set_internal_max_weight(3000);

   set_objects(
      DIR + "/objects/small_rock", 
      DIR + "/objects/large_rock"
   );
}
