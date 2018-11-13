#include "../domain.h"

inherit "/std/object";
inherit "/std/modules/m_block_exits";

void setup() {

}

void create(void) {
   ::create();
   set_id("дверь");
   add_ids("поле", "силовое поле");
   set_short("Мерцающее синим светом силовое поле");
   set_long("Это силовое поле перекрывает путь на север.");
   set_obj_i_name("силовое поле");
   set_obj_r_name("силового поля");
   set_obj_d_name("силовому полю");
   set_obj_v_name("силовое поле");
   set_obj_t_name("силовым полем");
   set_obj_p_name("силовом поле");
   set_obj_gender("neither");
   add_block("север");
   set_gettable(0);
}

int do_block(object who) {
   if (query_mortal(who)) {
      write("Поле отталкивает вас, когда вы пытаетесь пройти через него.\n");
      this_environment()->tell_room(this_player(), 
         this_player()->query_Name() + " отталкивает силовым полем.");
      return 1;
   } 
   write("Вы проходите сквозь силовое поле.\n");
   return 0;
}
