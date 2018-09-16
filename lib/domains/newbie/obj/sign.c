#include "../domain.h"

inherit "/std/sign";

void setup(void) {
   set_id("знак");
   set_long("На прибитом к дереву ржавыми гвоздями знаке что-то написано.");
   set_short("Деревянный знак");  
   set_obj_i_name("знак");
   set_obj_r_name("знака");
   set_obj_d_name("знаку");
   set_obj_v_name("знак");
   set_obj_t_name("знаком");
   set_obj_p_name("знаке");
   set_obj_gender("male");
   set_message("Добро пожаловать в зону для новичков. Если вы один из них, " +
      "то лезьте внутрь норы, не прогадаете.");
}
