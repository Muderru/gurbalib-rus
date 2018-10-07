/* Created by Fudge */

inherit "/std/object";
inherit "/std/modules/m_readable";

void create(void) {
   ::create();
   set_id("знак");
   set_short("Деревянный знак");
   set_long("Самый обычный знак. Похоже на нем что-то написано.");
   set_obj_i_name("знак");
   set_obj_r_name("знака");
   set_obj_d_name("знаку");
   set_obj_v_name("знак");
   set_obj_t_name("знаком");
   set_obj_p_name("знаке");
   set_obj_gender("male");   
   set_gettable(0);
}
