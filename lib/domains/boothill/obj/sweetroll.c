#include "../domain.h"

inherit "/std/object";

void setup(void) {
   set_id("рулет");
   add_id("сладкий");
   add_id("сладкий рулет");
   set_short("Очень аппетитный и сладкий рулет");
   set_long("При виде на него у вас начинают течь слюнки.");
   set_obj_i_name("сладкий рулет");
   set_obj_r_name("сладкого рулета");
   set_obj_d_name("сладкому рулету");
   set_obj_v_name("сладкий рулет");
   set_obj_t_name("сладким рулетом");
   set_obj_p_name("сладком рулете");
   set_obj_gender("male");
   set_eatable(1);
   set_gettable(1);
   set_value(15);
   set_weight(2);
}

int do_eat(void) {
   int x;

   x = random(5) + 1;
   write("Это божественно.");
     if (this_player()->query_gender() == "male") {
   this_player()->query_environment()->tell_room(this_player(),
      this_player()->query_Name() + 
      " съел его рулет.\n");
   } else if (this_player()->query_gender() == "female") {
   this_player()->query_environment()->tell_room(this_player(),
      this_player()->query_Name() + 
      " съела ее рулет.\n");
   } else {
   this_player()->query_environment()->tell_room(this_player(),
      this_player()->query_Name() + 
      " съело его рулет.\n");
   }

   this_player()->increase_hp(x);
   this_object()->destruct();
}

