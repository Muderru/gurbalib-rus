inherit ob "/std/object";
inherit wield "/std/modules/m_wieldable";
inherit "/std/armor";

void setup(void);

void create(void) {
   ob::create();
   wield::create();
   set_id("щит");
   set_obj_i_name("щит");
   set_obj_r_name("щита");
   set_obj_d_name("щиту");
   set_obj_v_name("щит");
   set_obj_t_name("щитом");
   set_obj_p_name("щите");
   set_obj_gender("male");
}
